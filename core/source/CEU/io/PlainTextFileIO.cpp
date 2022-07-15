#include <CEU/io/PlainTextFileIO.hpp>

namespace CEU
{
PlainTextFileIO::PlainTextFileIO(const std::string &filepath, bool append) :
    _inputStream {filepath, append}, _outputStream {filepath}
{
}

void PlainTextFileIO::close()
{
    _outputStream.close();
    _inputStream.close();
}

std::string PlainTextFileIO::read()
{
    _inputStream.close();
    return _outputStream.read();
}

std::string PlainTextFileIO::read(std::size_t nbChars)
{
    _inputStream.close();
    return _outputStream.read(nbChars);
}

void PlainTextFileIO::write(const std::string &value)
{
    _outputStream.close();
    _inputStream.write(value);
}
}