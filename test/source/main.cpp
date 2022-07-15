#include <iostream>

#include <CEU/memory/LinuxProcess.hpp>
#include <CEU/io/PlainTextFileIO.hpp>

#include "User.hpp"

/**
 * The entry point
 *
 * \return The status code
 */
int main()
{
    CEU::PlainTextFileIO plfio {"data.txt", false};
    test::User userToWrite {"Dany", "Pignoux", 24};

    std::string userAge {std::to_string(userToWrite.getAge())};

    // Write the user data in file
    plfio.write(userToWrite.getFirstname());
    plfio.write(userToWrite.getLastname());
    plfio.write(userAge);

    std::string fileContent {plfio.read()};

    std::cout << "FILE CONTENT : " << fileContent << '\n';

    // Read the user data from file
    // TODO: Fix problem can't read file when is already readed all
    test::User userToRead {
        plfio.read(userToWrite.getFirstname().size()),
        plfio.read(userToWrite.getLastname().size()),
        static_cast<unsigned int>(std::stoi(plfio.read(userAge.size())))
    };

    std::cout << "Firstname : " << userToRead.getFirstname() << '\n';
    std::cout << "Lastname : " << userToRead.getLastname() << '\n';
    std::cout << "Age : " << userToRead.getAge() << '\n';

    return 0;
}
