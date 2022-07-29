#pragma once
#include "Controller.h"
#include "RecommendationController.h"
#include "FileController.h"
#include "UserController.h"
#include "ViewHelper.h"

#include<string>
#include<iostream>
#include<regex>
// *
// * This class is used to set visual componets and interact with application's user
// * In MVC design pattern this is the view.
// * 
// * @version 1.3
// * @author kamila


//static bool contains(std::string input, std::string pattern);

// This is definition of enum used to label users requests
enum Action {
    SHOW_LIST,
    ADD_TASK,
    ADD_GROUP,
    EDIT_TASK,
    EDIT_GROUP,
    DELETE_TASK,
    DELETE_GROUP,
    RECCOMEND_TASK,
    MANAGE_MOODS,
    EXIT,
    INCORRECT
};

class View: public ViewHelper
{
    // *This is declaration of controllers
private:
    //Controller* theController;
    UserController* theUserController;
    RecommendationController* theController;
    //FileController* theFileController;
public:
    View();

    // *This method shows list of tasks gets from controller
    void showTasksList();
    // *This method asks user for title in console and sends adding new task request to controller
    void addTask();

    // *This method asks user for name in concole and sends adding new group request to controller
    void addGroup();
    // *This method asks user for data in console and sends controller group-delete request 
    //     *
    void deleteGroup();
    // *This method performs interaction with user (via console) during task editing process 
    //     * and sends controller task-edit request 
    //     *
    void editTask();
    // *This method performs interaction with user (via console) during task editing process 
    //     * and sends controller task-edit request 
    //     *
    void editGroup();
    // *This method asks user for data in console and sends controller task-delete request 
    //     *
    void deleteTask();

    void recommendTask();

    void manageMoods();
    // *This method shows errorMessage
    //     * @param errorMessage
    void showError(std::string errorMessage);

    // *This method coordinates menu actions and returns informetion about exit request
    //     * @return  isExit
    bool coordinateMenu();

    // *In case of non-argument given this is the main method of View
public:
    void showDisplay();
    // *In case of argument given this is the main method of view
    //     *@param userName
    void showDisplay(std::string userName);

    void clearMemory();
};


