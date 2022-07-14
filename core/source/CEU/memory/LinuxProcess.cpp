#include <dirent.h>
#include <sys/uio.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include "CEU/memory/LinuxProcess.hpp"
#include "CEU/exception/NotExistsFileException.hpp"
#include "CEU/exception/InvalidReadProcessMemoryDataException.h"
#include "CEU/exception/ErrorCode.hpp"
#include "CEU/exception/NotExistsProcessException.hpp"
#include "CEU/exception/InvalidWriteProcessMemoryDataException.h"

namespace CEU
{

LinuxProcess::LinuxProcess(const std::string &processName)
{
    if (processName.length() == 0)
    {
        throw InvalidReadProcessMemoryDataException(CEU_PROCESS_NAME_EMPTY);
    }

    //Try to open the /proc/ directory
    DIR *pDir = opendir("/proc/");

    if (!pDir)
    {
        throw NotExistsFileException("/proc");
    }

    struct dirent *pDirent;

    //Loop through all files and subdirectories of /proc/
    while (pDirent = readdir(pDir), pDirent != nullptr)
    {
        if (pDirent->d_type == DT_DIR)
        {
            std::string strProcID(pDirent->d_name);
            std::ifstream file {"/proc/" + strProcID + "/comm"};
            std::stringstream buffer;
            buffer << file.rdbuf();
            std::string fileContent {buffer.str()};
            file.close();

            if (fileContent == processName + '\n')
            {
                _pid = std::stoi(strProcID);
            }
        }
    }

    if (_pid == 0)
    {
        throw NotExistsProcessException(processName);
    }
}

int LinuxProcess::getPID() const
{
    return _pid;
}

void LinuxProcess::read(long address, void *buffer, size_t size) const
{
    struct iovec iovLocalAddressSpace[1] {nullptr};
    struct iovec iovRemoteAddressSpace[1] {nullptr};

    iovLocalAddressSpace[0].iov_base = buffer; //Store data in this buffer
    iovLocalAddressSpace[0].iov_len = size; //which has this size.
    iovRemoteAddressSpace[0].iov_base = reinterpret_cast<void *>(address); //The data comes from here
    iovRemoteAddressSpace[0].iov_len = size; //and has this size.

    ssize_t sSize = process_vm_readv(_pid, iovLocalAddressSpace, 1, iovRemoteAddressSpace, 1, 0);

    if (sSize != (ssize_t) size)
    {
        if (errno == 1)
        {
            throw InvalidReadProcessMemoryDataException(CEU_READ_PROCESS_MEMORY_DATA_NOT_PERMITTED);
        }
        else
        {
            throw InvalidReadProcessMemoryDataException(CEU_READ_PROCESS_MEMORY_DATA_FAILURE);
        }
    }
}

void LinuxProcess::write(long address, void *buffer, size_t size) const
{
    struct iovec iovLocalAddressSpace[1] {nullptr};
    struct iovec iovRemoteAddressSpace[1] {nullptr};

    iovLocalAddressSpace[0].iov_base = buffer; //Store data in this buffer
    iovLocalAddressSpace[0].iov_len = size; //which has this size.
    iovRemoteAddressSpace[0].iov_base = reinterpret_cast<void *>(address); //The data comes from here
    iovRemoteAddressSpace[0].iov_len = size; //and has this size.

    ssize_t sSize = process_vm_writev(_pid, iovLocalAddressSpace, 1, iovRemoteAddressSpace, 1, 0);

    if (sSize != (ssize_t) size)
    {
        if (errno == 1)
        {
            throw InvalidWriteProcessMemoryDataException(CEU_WRITE_PROCESS_MEMORY_DATA_NOT_PERMITTED);
        }
        else
        {
            throw InvalidWriteProcessMemoryDataException(CEU_WRITE_PROCESS_MEMORY_DATA_FAILURE);
        }
    }
}

int LinuxProcess::readInt(long address) const
{
    int value;

    read(address, &value, sizeof(int));

    return value;
}

void LinuxProcess::writeInt(long address, int value) const
{
    write(address, &value, sizeof(int));
}
}