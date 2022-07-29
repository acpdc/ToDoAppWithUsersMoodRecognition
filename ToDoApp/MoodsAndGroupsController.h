#pragma once
#include "DataBase.h"
#include "WrongIndexException.h"
#include <string>
#include <iostream>
class MoodsAndGroupsController
{
protected:
    //User* theUser;
    // *Data base is part of Model, which contains Groups and Tasks list
    DataBase* theDataBase;
public:
    MoodsAndGroupsController();
    std::string showGroupsList();
    std::string showMoodsList();

    std::string showGroupName(int groupNr);

    std::string showMoodName(int nr);

    std::string showMood(int groupNr);

    void addGroup(std::string groupName);
    void addGroup(std::string groupName, int priorityNumber);
    void addMood(std::string moodName, double rating);

    void changeGroupName(int groupNr, std::string name);
    void changeMoodName(int id, std::string name);

    void changeMoodRating(int id, double rating);

    void deleteGroup(int id);
    void deleteMood(int id);

    int getGroupsCount();

    int getMoodsCount();

    void clearMemory();
};

