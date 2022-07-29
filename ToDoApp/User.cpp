#include "User.h"

User::User()
{
    this->name = "";
}
// *constructs user with newName as name
//     * @param newName
User::User(std::string newName)
{
    this->name = newName;
}
// *This method returns name
//     *@return name
std::string User::getName()
{
    return name;
}
// *This method sets name
//     * @param newName
void User::setName(std::string newName)
{
    this->name = newName;
}

