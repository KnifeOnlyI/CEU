#ifndef CEU_LINUXPROCESS_HPP
#define CEU_LINUXPROCESS_HPP

#include <string>

namespace CEU
{
/**
 * Represent a linux process
 */
class LinuxProcess
{
public:

    /**
     * Create a new instance
     *
     * \param processName The process name
     */
    explicit LinuxProcess(const std::string &processName);

    /**
     * Get the PID
     *
     * \return The PID
     */
    [[nodiscard]] int getPID() const;

    /**
     * Read a data of the specified length at the specified address
     *
     * \param address The address to read
     * \param buffer The buffer where to store data
     * \param size The size to read
     */
    void read(long address, void *buffer, size_t size) const;

    /**
     * Write a data of the specified length at the specified address
     *
     * \param address The address to write
     * \param buffer The buffer where data to write are stored
     * \param size The size to write
     */
    void write(long address, void *buffer, size_t size) const;

    /**
     * Read a int at the specified address
     *
     * \param address The address to read
     *
     * \return The read value
     */
    [[nodiscard]] int readInt(long address) const;

    /**
     * Write a int at the specified address
     *
     * \param address The address to write
     * \param value The value to write
     */
    void writeInt(long address, int value) const;

private:

    /** \var The PID */
    int _pid;
};
}

#endif //CEU_LINUXPROCESS_HPP
