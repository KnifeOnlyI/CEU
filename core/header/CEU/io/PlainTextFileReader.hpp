#ifndef CEU_PLAINTEXTFILEREADER_HPP
#define CEU_PLAINTEXTFILEREADER_HPP

#include <fstream>

namespace CEU
{
/**
 * The class to read a plain text file
 */
class PlainTextFileReader
{
public:

    /**
     * Create a new instance
     *
     * \param filepath The filepath
     */
    explicit PlainTextFileReader(std::string filepath);

    /**
     * Destroy the instance
     */
    virtual ~PlainTextFileReader();

    /**
     * Open the stream
     */
    void open();

    /**
     * Close the stream
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

private:

    /** \var The stream to read */
    std::ifstream _stream;

    /** \var The filepath */
    std::string _filepath;
};
}

#endif //CEU_PLAINTEXTFILEREADER_HPP
