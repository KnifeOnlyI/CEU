#ifndef CEU_INVALIDWRITEPROCESSMEMORYDATAEXCEPTION_H
#define CEU_INVALIDWRITEPROCESSMEMORYDATAEXCEPTION_H

#include <string>
#include "BaseException.hpp"

namespace CEU
{
/**
 * The exception for invalid process memory data writing
 */
class InvalidWriteProcessMemoryDataException : public BaseException
{
public:

    /**
     * Create a new instance
     *
     * \param message The message
     */
    explicit InvalidWriteProcessMemoryDataException(const std::string &message) :
        BaseException(message)
    {
    }
};
}

#endif //CEU_INVALIDWRITEPROCESSMEMORYDATAEXCEPTION_H
