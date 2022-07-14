#include <iostream>

#include "CEU/memory/LinuxProcess.hpp"

/**
 * The entry point
 *
 * \param argc The number of arguments
 * \param argv
 *  1 - The program path (Automatically set)
 *  2 - The name of other process to open (e.g : test)
 *  3 - The address of variable to read/write (e.g : 0x7ffffae286dc)
 *
 * \return The status code
 */
int main(int argc, char *argv[])
{
    long address {std::strtol(argv[2], nullptr, 16)};
    CEU::LinuxProcess process {argv[1]};

    std::cout << "PID : " << process.getPID() << '\n';
    std::cout << "OLD VALUE : " << process.readInt(address) << '\n';

    process.writeInt(address, 12);

    std::cout << "NEW VALUE : " << process.readInt(address) << '\n';

    return 0;
}
