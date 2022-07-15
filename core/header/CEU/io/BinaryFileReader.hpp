#ifndef CEU_BINARYFILEREADER_HPP
#define CEU_BINARYFILEREADER_HPP

#include <fstream>

namespace CEU
{
/**
 * The class to read a binary file
 */
class BinaryFileReader
{
public:

    /**
     * Create a new instance
     *
     * \param filepath The filepath
     */
    explicit BinaryFileReader(std::string filepath);

    /**
     * Destroy the instance
     */
    virtual ~BinaryFileReader();

    /**
     * Open the stream
     */
    void open();

    /**
     * Close the stream
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
     * \return The read value
     */
    std::string readString();

private:

    /** \var The stream to read */
    std::ifstream _stream;

    /** \var The filepath */
    std::string _filepath;
};
}

#endif //CEU_BINARYFILEREADER_HPP
