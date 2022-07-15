#ifndef CEU_PLAINTEXTFILEWRITER_HPP
#define CEU_PLAINTEXTFILEWRITER_HPP

#include <fstream>

namespace CEU
{
/**
 * The class to write a plain text file
 */
class PlainTextFileWriter
{
public:

    /**
     * Create a new instance
     *
     * \param filepath The filepath
     * \param append TRUE to append the new content to the already existing, FALSE to delete all and overwrite it
     */
    explicit PlainTextFileWriter(std::string filepath, bool append = true);

    /**
     * Destroy the instance
     */
    virtual ~PlainTextFileWriter();

    /**
     * Open the stream
     */
    void open();

    /**
     * Close the stream
     */
    void close();

    /**
     * Write a string value
     *
     * \param value The value to write
     */
    void write(const std::string &value);

private:

    /** \var The stream to write */
    std::ofstream _stream;

    /** \var The filepath */
    std::string _filepath;

    /** \var The append content flag */
    bool _append;
};
}

#endif //CEU_PLAINTEXTFILEWRITER_HPP
