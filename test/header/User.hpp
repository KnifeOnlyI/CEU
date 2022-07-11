#ifndef CEU_USER_HPP
#define CEU_USER_HPP

#include <string>

namespace test
{
/**
 * Represent a user
 */
class User
{
public:

    /**
     * Create a new user
     */
    User(std::string firstname, std::string lastname, unsigned int age);

    /**
     * Get the firstname
     *
     * \return The firstname
     */
    [[nodiscard]] const std::string &getFirstname() const;

    /**
     * Get the lastname
     *
     * \return The lastname
     */
    [[nodiscard]] const std::string &getLastname() const;

    /**
     * Get the age
     *
     * \return The age
     */
    [[nodiscard]] unsigned int getAge() const;

private:

    /** \var The firstname */
    std::string _firstname;

    /** \var The lastname */
    std::string _lastname;

    /** \var The age */
    unsigned int _age;
};
}

#endif //CEU_USER_HPP
