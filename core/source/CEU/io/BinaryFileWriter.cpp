#include <CEU/io/BinaryFileWriter.hpp>
#include <iostream>
#include <utility>

namespace CEU
{
BinaryFileWriter::BinaryFileWriter(std::string filepath, bool append) :
    _filepath {std::move(filepath)}, _append {append}
{
    open();
}

BinaryFileWriter::~BinaryFileWriter()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

void BinaryFileWriter::open()
{
    if (!_stream.is_open())
    {
        if (_append)
        {
            _stream.open(_filepath, std::ios::out | std::ios::binary | std::ios::app);
        }
        else
        {
            _stream.open(_filepath, std::ios::out | std::ios::binary);
        }

        if (!_stream.is_open())
        {
            std::cerr << "Cannot open a binary file writer\n";
            exit(-1);
        }
    }
}

void BinaryFileWriter::close()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

void BinaryFileWriter::writeSize(std::size_t value)
{
    open();
    _stream.write(reinterpret_cast<const char *>(&value), sizeof(std::size_t));
}

void BinaryFileWriter::writeUnsignedInt(unsigned int value)
{
    open();
    _stream.write(reinterpret_cast<const char *>(&value), sizeof(unsigned int));
}

void BinaryFileWriter::writeString(const std::string &value)
{
    open();
    writeSize(value.size());
    _stream.write(value.c_str(), static_cast<long>(value.size()));
}
}