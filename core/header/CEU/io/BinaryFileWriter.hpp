#ifndef CEU_BINARYFILEWRITER_HPP
#define CEU_BINARYFILEWRITER_HPP

#include <cstddef>
#include <string>
#include <fstream>

namespace CEU
{
/**
 * The class to write a binary file
 */
class BinaryFileWriter
{
public:

    /**
     * Create a new instance
     *
     * \param filepath The filepath
     * \param append TRUE to append the new content to the already existing, FALSE to delete all and overwrite it
     */
    explicit BinaryFileWriter(std::string filepath, bool append = true);

    /**
     * Open the stream
     */
    void open();

    /**
     * Close the stream
     */
    void close();

    /**
     * Destroy the instance
     */
    virtual ~BinaryFileWriter();

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

    /** \var The stream to write */
    std::ofstream _stream;

    /** \var The filepath */
    std::string _filepath;

    /** \var The append content flag */
    bool _append;
};
}

#endif //CEU_BINARYFILEWRITER_HPP
