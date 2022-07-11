#include <CEU/io/BinaryFileReader.hpp>
#include <iostream>
#include <utility>

namespace CEU
{
BinaryFileReader::BinaryFileReader(std::string filepath) :
    _filepath {std::move(filepath)}
{
    open();
}

BinaryFileReader::~BinaryFileReader()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

void BinaryFileReader::open()
{
    if (!_stream.is_open())
    {
        _stream.open(_filepath, std::ios::out | std::ios::binary);

        if (!_stream.is_open())
        {
            std::cerr << "Cannot open a binary file reader\n";
            exit(-1);
        }
    }
}

void BinaryFileReader::close()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

std::size_t BinaryFileReader::readSize()
{
    open();

    std::streamsize value;

    _stream.read(reinterpret_cast<char *>(&value), sizeof(size_t));

    return value;
}

unsigned int BinaryFileReader::readUnsignedInt()
{
    open();

    unsigned int value;

    _stream.read(reinterpret_cast<char *>(&value), sizeof(unsigned int));

    return value;
}

std::string BinaryFileReader::readString(std::size_t nbChars)
{
    open();

    std::string value;
    char *buffer;

    buffer = new char[nbChars + 1];

    _stream.read(buffer, static_cast<long>(nbChars));

    buffer[nbChars] = '\0';
    value = buffer;

    delete[] buffer;

    return value;
}

std::string BinaryFileReader::readString()
{
    return readString(readSize());
}
}