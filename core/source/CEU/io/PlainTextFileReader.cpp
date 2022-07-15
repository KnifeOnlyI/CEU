#include <CEU/io/PlainTextFileReader.hpp>
#include "CEU/exception/FileReaderException.hpp"
#include "CEU/exception/ErrorCode.hpp"

namespace CEU
{
PlainTextFileReader::PlainTextFileReader(std::string filepath) :
    _filepath {std::move(filepath)}
{
}

PlainTextFileReader::~PlainTextFileReader()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

void PlainTextFileReader::open()
{
    if (!_stream.is_open())
    {
        _stream.open(_filepath, std::ios::out);

        if (!_stream.is_open())
        {
            throw FileReaderException(CEU_PLAIN_TEXT_FILE_READER_UNKNOW_ERROR);
        }
    }
}

void PlainTextFileReader::close()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

std::string PlainTextFileReader::read()
{
    std::string value;

    while (!_stream.eof())
    {
        value.append(read(1));
    }

    _stream.seekg(0);

    return value;
}

std::string PlainTextFileReader::read(std::size_t nbChars)
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
}