#ifndef CEU_NOTEXISTSPROCESSEXCEPTION_HPP
#define CEU_NOTEXISTSPROCESSEXCEPTION_HPP

#include "BaseException.hpp"

namespace CEU
{
/**
 * The exception for not existing processes
 */
class NotExistsProcessException : public BaseException
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     * \param customMessage TRUE to set the message is the entire message, FALSE to set message is a part of predefined error message
     */
    explicit NotExistsProcessException(const std::string &message, bool customMessage = false) :
        BaseException(message)
    {
        if (!customMessage)
        {
            setMessage("Not existing process : " + message);
        }
    }
};
}

#endif //CEU_NOTEXISTSPROCESSEXCEPTION_HPP
