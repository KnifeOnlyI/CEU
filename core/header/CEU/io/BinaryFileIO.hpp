#ifndef CEU_BINARYFILEIO_HPP
#define CEU_BINARYFILEIO_HPP

#include <CEU/io/BinaryFileReader.hpp>
#include <CEU/io/BinaryFileWriter.hpp>

namespace CEU
{
/**
 * The class to read/write a binary file
 */
class BinaryFileIO
{
public:

    /**
     * Create a new instance
     *
     * \param filepath The filepath
     * \param append TRUE to append the new content to the already existing, FALSE to delete all and overwrite it
     */
    explicit BinaryFileIO(const std::string &filepath, bool append = true);

    /**
     * Close the streams
     */
    void close();

    /**
     * Read a size value
     *
     * \return The read value
     */
    std::size_t readSize();

    /**
     * Read an unsigned int value
     *
     * \param value The value to read
     *
     * \return The read value
     */
    unsigned int readUnsignedInt();

    /**
     * Read a specified number of chars and put them in a string
     *
     * \param value The number of chars to read
     *
     * \return The read value
     */
    std::string readString(std::size_t nbChars);

    /**
     * Read a string value
     *
     * \param value The value to read
     *
     * \param The read value
     */
    std::string readString();

    /**
     * Write a size value
     *
     * \param value The value to write
     */
    void writeSize(std::size_t value);

    /**
     * Write an unsigned int value
     *
     * \param value The value to write
     */
    void writeUnsignedInt(unsigned int value);

    /**
     * Write a string value
     *
     * \param value The value to write
     */
    void writeString(const std::string &value);

private:

    /** \var The input stream (to write) */
    CEU::BinaryFileWriter _inputStream;

    /** \var The output stream (to read) */
    CEU::BinaryFileReader _outputStream;
};
}

#endif //CEU_BINARYFILEIO_HPP
