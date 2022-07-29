#pragma once
#include <string>

class User
{
    // *the name of the user
private:
    std::string name;
    // *constructs user with no data
public:
    User();
    // *constructs user with newName as name
    //     * @param newName
    User(std::string newName);
    // *This method returns name
    //     *@return name
    std::string getName();
    // *This method sets name
    //     * @param newName
    void setName(std::string newName);
};

