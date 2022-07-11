#include <iostream>

#include "User.hpp"
#include "CEU/io/BinaryFileIO.hpp"

int main()
{
    CEU::BinaryFileIO bfio {"data.dat", true};
    test::User userToWrite {"Dany", "Pignoux", 24};

    // Write the user data in file
    bfio.writeString(userToWrite.getFirstname());
    bfio.writeString(userToWrite.getLastname());
    bfio.writeUnsignedInt(userToWrite.getAge());

    // Read the user data from file
    test::User userToRead {bfio.readString(), bfio.readString(), bfio.readUnsignedInt()};

    std::cout << "Firstname : " << userToRead.getFirstname() << '\n';
    std::cout << "Lastname : " << userToRead.getLastname() << '\n';
    std::cout << "Age : " << userToRead.getAge() << '\n';

    return 0;
}
