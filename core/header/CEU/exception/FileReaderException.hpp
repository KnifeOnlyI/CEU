#ifndef CEU_FILEREADEREXCEPTION_HPP
#define CEU_FILEREADEREXCEPTION_HPP

#include "BaseException.hpp"

namespace CEU
{
/**
 * The exception for file reader
 */
class FileReaderException : public BaseException
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     */
    explicit FileReaderException(const std::string &message) :
        BaseException(message)
    {
    }
};
}

#endif //CEU_FILEREADEREXCEPTION_HPP
