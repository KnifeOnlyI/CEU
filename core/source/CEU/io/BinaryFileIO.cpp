#include <CEU/io/BinaryFileIO.hpp>

namespace CEU
{
BinaryFileIO::BinaryFileIO(const std::string &filepath, bool append) :
    _inputStream {filepath, append}, _outputStream {filepath}
{
}

void BinaryFileIO::close()
{
    _outputStream.close();
    _inputStream.close();
}

std::size_t BinaryFileIO::readSize()
{
    _inputStream.close();

    return _outputStream.readSize();
}

unsigned int BinaryFileIO::readUnsignedInt()
{
    _inputStream.close();

    return _outputStream.readUnsignedInt();
}

std::string BinaryFileIO::readString(std::size_t nbChars)
{
    _inputStream.close();

    return _outputStream.readString(nbChars);
}

std::string BinaryFileIO::readString()
{
    _inputStream.close();

    return _outputStream.readString();
}

void BinaryFileIO::writeSize(std::size_t value)
{
    _outputStream.close();
    _inputStream.writeSize(value);
}

void BinaryFileIO::writeUnsignedInt(unsigned int value)
{
    _outputStream.close();
    _inputStream.writeUnsignedInt(value);
}

void BinaryFileIO::writeString(const std::string &value)
{
    _outputStream.close();
    _inputStream.writeString(value);
}
}