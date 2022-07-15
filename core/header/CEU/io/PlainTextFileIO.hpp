#ifndef CEU_PlainTextFileIO_HPP
#define CEU_PlainTextFileIO_HPP

#include <CEU/io/PlainTextFileReader.hpp>
#include <CEU/io/PlainTextFileWriter.hpp>

namespace CEU
{
/**
 * The class to read/write a plain text file
 */
class PlainTextFileIO
{
public:

    /**
     * Create a new instance
     *
     * \param filepath The filepath
     * \param append TRUE to append the new content to the already existing, FALSE to delete all and overwrite it
     */
    explicit PlainTextFileIO(const std::string &filepath, bool append = true);

    /**
     * Close the streams
     */
    void close();

    /**
     * Read all file content
     *
     * \return The read value
     */
    std::string read();

    /**
     * Read the specified number of chars
     *
     * \param nbChars The number of chars to read
     *
     * \return The read value
     */
    std::string read(std::size_t nbChars);

    /**
     * Write a string value
     *
     * \param value The value to write
     */
    void write(const std::string &value);

private:

    /** \var The input stream (to write) */
    CEU::PlainTextFileWriter _inputStream;

    /** \var The output stream (to read) */
    CEU::PlainTextFileReader _outputStream;
};
}

#endif //CEU_PlainTextFileIO_HPP
