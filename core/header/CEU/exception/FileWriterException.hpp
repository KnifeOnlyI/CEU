#ifndef CEU_FILEWRITEREXCEPTION_HPP
#define CEU_FILEWRITEREXCEPTION_HPP

#include "BaseException.hpp"

namespace CEU
{
/**
 * The exception for file writer
 */
class FileWriterException : public BaseException
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     */
    explicit FileWriterException(const std::string &message) :
        BaseException(message)
    {
    }
};
}

#endif //CEU_FILEWRITEREXCEPTION_HPP
