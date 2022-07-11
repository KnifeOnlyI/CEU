#include "User.hpp"

namespace test
{
User::User(std::string firstname, std::string lastname, unsigned int age) :
    _firstname {std::move(firstname)}, _lastname {std::move(lastname)}, _age {age}
{
}

const std::string &User::getFirstname() const
{
    return _firstname;
}

const std::string &User::getLastname() const
{
    return _lastname;
}

unsigned int User::getAge() const
{
    return _age;
}
}