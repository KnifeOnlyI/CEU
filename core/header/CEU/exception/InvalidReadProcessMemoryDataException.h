#ifndef CEU_INVALIDREADPROCESSMEMORYDATAEXCEPTION_H
#define CEU_INVALIDREADPROCESSMEMORYDATAEXCEPTION_H

#include <string>
#include "BaseException.hpp"

namespace CEU
{
/**
 * The exception for invalid process memory data reading
 */
class InvalidReadProcessMemoryDataException : public BaseException
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     */
    explicit InvalidReadProcessMemoryDataException(const std::string &message) :
        BaseException(message)
    {
    }
};
}

#endif //CEU_INVALIDREADPROCESSMEMORYDATAEXCEPTION_H
