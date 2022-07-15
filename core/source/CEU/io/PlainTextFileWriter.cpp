#include <CEU/io/PlainTextFileWriter.hpp>
#include "CEU/exception/FileWriterException.hpp"
#include "CEU/exception/ErrorCode.hpp"

namespace CEU
{
PlainTextFileWriter::PlainTextFileWriter(std::string filepath, bool append) :
    _filepath {std::move(filepath)}, _append {append}
{
}

PlainTextFileWriter::~PlainTextFileWriter()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

void PlainTextFileWriter::open()
{
    if (!_stream.is_open())
    {
        if (_append)
        {
            _stream.open(_filepath, std::ios::in | std::ios::app);
        }
        else
        {
            _stream.open(_filepath, std::ios::in);
        }

        if (!_stream.is_open())
        {
            throw FileWriterException(CEU_PLAIN_TEXT_FILE_WRITER_UNKNOW_ERROR);
        }
    }
}

void PlainTextFileWriter::close()
{
    if (_stream.is_open())
    {
        _stream.close();
    }
}

void PlainTextFileWriter::write(const std::string &value)
{
    open();
    _stream.write(value.c_str(), static_cast<long>(value.size()));
}
}