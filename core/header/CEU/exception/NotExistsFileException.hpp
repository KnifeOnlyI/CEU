#ifndef CEU_NOTEXISTSFILEEXCEPTION_HPP
#define CEU_NOTEXISTSFILEEXCEPTION_HPP

#include "BaseException.hpp"

namespace CEU
{
/**
 * The exception for not exists file
 */
class NotExistsFileException : public BaseException
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     * \param customMessage TRUE to set the message is the entire message, FALSE to set message is a part of predefined error message
     */
    explicit NotExistsFileException(const std::string &message, bool customMessage = false) :
        BaseException(message)
    {
        if (!customMessage)
        {
            setMessage("Not existing file : " + message);
        }
    }
};
}

#endif //CEU_NOTEXISTSFILEEXCEPTION_HPP
