#pragma once
#include "DataBase.h"
#include "WrongIndexException.h"
#include "Group.h"
#include "Task.h"
#include<string>
#include<vector>
// *
// * This class collect and groups other model's class.
// * In future it will implements handling with files.
// * 
// * 
// * @version 1.0
// * @author kamila
class DataBase
{
    // *The list of Tasks objects
    //     * 
private:
    //std::vector<> theTasksList = java.util.LinkedList();
    //TODO obiekty typu Item List
    std::vector<Task*> theTasksList;
    // *The list of Groups objects
    //     *
    //std::vector<> theGroupsList = java.util.LinkedList();
    std::vector<Group*> theGroupsList;
    // *This method returns theTasksList
    //    * 
    //    * @return theTasksList
    vector<Mood*> theMoodList;

public:
    DataBase() {
        theGroupsList.push_back(new Group("default", LOW));
        theGroupsList.push_back(new Group("school", HIGH));
        theGroupsList.push_back(new Group("work",HIGH ));
        theGroupsList.push_back(new Group("hobby",MEDIUM ));
        theGroupsList.push_back(new Group("home",MEDIUM ));
        theGroupsList.push_back(new Group("freeTime", LOW));
        theMoodList.push_back(new Mood("default", 2.5));
        theMoodList.push_back(new Mood("tired", 2.0));
        theMoodList.push_back(new Mood("exhausted", 0.5));
        theMoodList.push_back(new Mood("sad", 1.5));
        theMoodList.push_back(new Mood("bored",3.0));
        theMoodList.push_back(new Mood("concentrated", 4.0));
        theMoodList.push_back(new Mood("enthusiastic",5.0));
        theMoodList.push_back(new Mood("happy", 4.5));
    };

  /*  friend class Controller;
    friend class MoodController;*/


    std::vector<Task*> getTasksList();
    // *This method returns theGroupsList
    //    * 
    //    * @return theGroupsList
    std::vector<Group*> getGroupsList();

    std::vector<Mood*> getMoodList();

    // *This method returns Task with given id and throws WrongIndexException when given id is not correct
    //    * 
    //    * @throws WrongIndexException
    //    * @param taskIndex
    //    * @return theTasksList.get(taskIndex)

    Task* getTask(int taskIndex);
    // *This method returns Group with given id and throws WrongIndexException when given id is not correct
    //     * 
    //     * @throws WrongIndexException
    //     * @param groupIndex
    //     * @return theGroupsList.get(groupIndex);
    Group* getGroup(int groupIndex);

    Mood* getMood(int moodIndex);

    // *This method returns size of tasks list
    //     * 
    //     * @return theTasksList.size()
    int getTasksCount();

    // *This method returns size of groups list
    //     * 
    //     * @return theGroupsList.size()
    int getGroupsCount();

    int getMoodCount();

    void addTask(std::string taskTitle, string details);

    void addTask(std::string taskTitle);

    // *This method adds new task without group to the Tasks List
    //     * 
    //     * @param taskTitle
    //     * @param userName
    // void addTask(std::string taskTitle, std::string userName) {};

    // *This method adds new task with group to the Tasks List and throws WrongIndexException 
    //     * when given group id is not correct
    //     * 
    //     * @throws WrongIndexException
    //     * @param taskTitle
    //     * @param groupNumber
    //     * @param userName
    void addTask(std::string taskTitle, int groupNumber, std::string userName) {};
    void addTask(std::string taskTitle, int groupNumber, int moodNumber, string date, string deadline, string taskDetails);
    void addGroup(std::string groupName, Priority groupPriority);
    void addGroup(std::string groupName, int priorityNumber);
    void addMood(std::string name, double rating);
    // *This method adds new group to the Groups List
    //     * 
    //     * @param groupName
    void addGroup(std::string groupName) {};
    // * This method changes title of task with given id and throws WrongIndexException when id is not correct.
    //     * 
    //     * @throws WrongIndexException
    //     * @param taskNr
    //     * @param newTitle
    void changeTaskTitle(int taskNr, std::string newTitle);
    void changeTaskDetails(int taskNr, string text);
    // * This method changes group of task with given id and throws WrongIndexException 
    //     *  when given id is not correct.
    //     * 
    //     * @throws WrongIndexException
    //     * @param taskNr
    //     * @param groupNumber
    void changeTaskGroup(int taskNr, int groupNumber);

    void changeTaskMood(int taskNr, int moodNumber);

    void changeTaskDeadline(int taskNr, tm deadline);
    void changeTaskDeadline(int taskNr, int deadline);

    // * This method changes name of group with given id and throws WrongIndexException 
    //     * when given id is not correct.
    //     * 
    //     * @throws WrongIndexException
    //     * @param groupNr
    //     * @param name
    void changeGroupName(int groupNr, std::string name);
    void changeGroupPriority(int groupNr, int priorityNumber);


    // *This method deletes task from Tasks List and throws WrongIndexException when given id is not correct.
    //     * 
    //     * @throws WrongIndexException
    //     * @param numberToDelete
    void deleteTask(int numberToDelete);

    // *This method deletes group from Groups List and throws WrongIndexException when given id is not correct
    //     * 
    //     * @throws WrongIndexException
    //     * @param numberToDelete
    void deleteGroup(int numberToDelete);

    void changeWholeTask(int index, string name, string details, int groupIndex, int moodIndex, string daedline);

    void changeTaskStatus(int id, Status status);

    void changeWholeGroup(int ingroupNrdex, string name, int priorityNumber);

    void changeWholeMood(int index, string name, double rating);

    void changeMoodName(int index, string name);

    void changeMoodRating(int index, double rating);

    void deleteMood(int numberToDelete);

    // *This method is clearing list of groups
    void clearGroupsList();

    // *This method is clearing list of tasks
    void clearTasksList();

    void clearMoodList();

    // *This method is not implemented yet, but will be used in future to perform stream operation
    void streamTasksGrouped();

    string tmToString(tm date);
};


