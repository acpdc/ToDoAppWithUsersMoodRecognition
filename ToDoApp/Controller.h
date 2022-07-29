#pragma once
#include "MoodsAndGroupsController.h"
#include "WrongIndexException.h"
#include <string>
#include <iostream>

class Controller : public MoodsAndGroupsController
{

    // *This constructs Controller

  public:
    Controller();

    std::string showTasksList();
    std::string showTasksGroupedList();
    std::string showTasksTitle(int taskNr);
    std::string showTasksGroup(int taskNr);
    std::string showTask(int taskNr);

    void getTasksFromGroupMap(int groupId);

    void addTask(std::string taskTitle);
    void addTask(std::string taskTitle, int groupNumber);

    void addTask(std::string title, std::string details);
    void addItem(Item* item);
    Item* getItemFromFile(char who, fstream& fileStream);

    string getItemFileFormat(char who);

    void changeTaskGroup(int taskNr, int groupNumber);
    void changeTaskMood(int taskNr, int moodNr);
    void changeTaskDeadline(int taskNr, tm deadline);
    void changeTaskDeadline(int taskNr, int deadline);
    void changeTaskTitle(int, std::string);

    void changeTaskDetails(int taskNr, std::string text);

    void deleteTask(int numberToDelete);

    int getTasksCount();
    tm stringToTm(string date);
    /*Przeniesione do UserController
    void setUserName(std::string userName);
    std::string getUserName();
    */
    void clearMemory();

};

