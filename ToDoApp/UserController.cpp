#include "UserController.h"

void UserController::setUserName(std::string userName)
{
    theUser->setName(userName);
}
// *This method gets name of user
//     * @return User.name
std::string UserController::getUserName()
{
    return theUser->getName();
}