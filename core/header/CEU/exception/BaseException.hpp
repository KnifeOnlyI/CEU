#ifndef CEU_BASEEXCEPTION_HPP
#define CEU_BASEEXCEPTION_HPP

#include <exception>
#include <string>

namespace CEU
{
/**
 * The base class for all exceptions
 */
class BaseException : public std::exception
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     */
    explicit BaseException(std::string message) :
        _message {std::move(message)}
    {
    }

    /**
     * Get the message
     *
     * \return The message
     */
    [[nodiscard]] const char *what() const noexcept override
    {
        return _message.c_str();
    }

    /**
     * Get the this->what() message as string
     *
     * \return The what message as string
     */
    [[nodiscard]] const std::string &getMessage() const
    {
        return _message;
    }

    /**
     * Set the message
     *
     * \param message The new message
     */
    void setMessage(const std::string &message)
    {
        _message = message;
    }

private:

    /** \var The message */
    std::string _message;
};
}

#endif //CEU_BASEEXCEPTION_HPP
