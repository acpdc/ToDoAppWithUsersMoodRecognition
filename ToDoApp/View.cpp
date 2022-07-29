#include "View.h"
// *
// * This class is used to set visual componets and interact with application's user
// * In MVC design pattern this is the view.
// * 
// * @version 1.3
// * @author kamila



View::View()
{
    //this->theController = new Controller(); 
    this->theUserController = new UserController();
    this->theController = new RecommendationController();
    //this->theFileController = new FileController();
}

// *This method shows list of tasks gets from controller
void View::showTasksList()
{
    if (theController->getTasksCount() > 0)
    {
        std::cout << theController->showTasksList() << std::endl;
        /*std::cout << "Do you want to see grouped task? n/y" << std::endl;
        std::string answer = "";
        bool decided = false;
        while (!decided)
        {
            std::cin >> answer;

            if (yesOrNo(answer) == "NO")
            {
                decided = true;
            }
            else
                if (yesOrNo(answer) == "YES")
                {
                    decided = true;
                    try
                    {
                        std::cout << theController->showTasksGroupedList() << std::endl;
                    }
                    catch (std::exception e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else
                {
                    std::cout << "You need to enter y or n" << std::endl;
                }
        }*/
    }
    else
    {
        std::cout << "Your task\'s list is empty" << std::endl;
    }
}

// *This method asks user for title in console and sends adding new task request to controller
void View::addTask()
{
    std::cout << "Type name of your task" << std::endl;
    std::string newTaskTitle = "";
    std::cin >> newTaskTitle;

    cout << "Type details and description of your task\n";
    string taskDetails ="";
    cin >> taskDetails;
    //crating basic task with title and details, later edit mood, group itd. (Controller: change, DataBase: set)
    theController->addTask(newTaskTitle, taskDetails);

    
    cout << "Type number of day you want to do this task or press 'd' to set default (dedaline one week from today) \n";
    string taskDeadline="";
    cin >> taskDeadline;
    
    int deadlineInt = 7;  //checkIntNumber(taskDeadline);
    
    if (!taskDeadline.empty()) {

        //struct tm taskDeadlineTm = theDataBase->getTaskDeadline();
        deadlineInt = checkIntNumber(taskDeadline);
        if (deadlineInt!=-1 || taskDeadline=="d") {
            theController->changeTaskDeadline((theController->getTasksCount() - 1), deadlineInt);
        }
        else{
            cout << "You haven't typed date of deadline in way this program can recognize. Try again\n";
            cin >> taskDeadline;
            deadlineInt = checkIntNumber(taskDeadline);
            if (taskDeadline == "" || deadlineInt==-1) {
                cout << "You haven't typed date of deadline in way this program can recognize. Default deadline set";
            }
            else {
                theController->changeTaskDeadline((theController->getTasksCount() - 1), deadlineInt);
            }
        }
    }


    //Group
    if (theController->getGroupsCount() != 0)
    {
        std::cout << "Do you want to add this task to existing group? n / y \nIf no, it will have default group\n" << std::endl;
        std::string answer = "";
        std::cin >> answer;
        bool decided = false;
        while (!decided)
        {
            if (answer=="n" || answer=="N")
            {
                decided = true;
            }
            else if (answer=="y" || answer=="Y")
                {
                    decided = true;
                    std::cout << "Avaible groups: " + theController->showGroupsList() << std::endl;
                    std::cout << "Please press group number" << std::endl;
                    int groupNr = 0;
                    std::cin >> groupNr;
                    try
                    {
                        //theController->addTask(newTaskTitle, groupNr - 1);
                        theController->changeTaskGroup((theController->getTasksCount() - 1), groupNr - 1);
                    }
                    catch (std::exception e)
                    {
                    }
                }
                else
                    {
                        std::cout << "You need to press y or n" << std::endl;
                    }
        }
    }

    std::cout << "Do you want to add this task to existing mood? n / y \nIf no, it will have default mood\n" << std::endl;
    std::string answer = "";
    std::cin >> answer;
    bool decided = false;
    while (!decided)
    {
        if (answer == "n" || answer == "N") decided = true;
        else if (answer == "y" || answer == "Y")
        {
            decided = true;
           std::cout << "Avaible moods: " + theController->showMoodsList() << std::endl;
            std::cout << "Please press mood number" << std::endl;
            int moodNr = 0;
            std::cin >> moodNr;
            try
            {
                theController->changeTaskMood((theController->getTasksCount() - 1), moodNr - 1);
            }
            catch (std::exception e)
            {
            }
        }
        else
        {
            std::cout << "You need to press y or n" << std::endl;
        }
    }
    
    std::cout << "Task: " << theController->showTasksTitle((theController->getTasksCount() - 1)) << " added successfully!" << std::endl;
}
// *This method asks user for name in concole and sends adding new group request to controller
void View::addGroup()
{
    std::cout << "Type name of group you want to create" << std::endl;
    std::string newGroupName = "";
    std::cin >> newGroupName;

    std::cout << "Which priority should have this group? \n\tLOW - press 1 \n\tAVERAGE (default) press 2\n\tHIGH - press 3" << std::endl;
    string input;
    cin >> input;

    while (checkIntNumber(input, 1, 3) == -1) {
        cout << "Type 1, 2 or 3\n";
        cin >> input;
    }

    theController->addGroup(newGroupName, (checkIntNumber(input, 1, 3)-1));
}
// *This method asks user for data in console and sends controller group-delete request 
//     *
void View::deleteGroup()
{
    if (theController->getGroupsCount() != 0)
    {
        string nrToDelete = "";
        try
        {
            std::cout << "Avaible task\'s groups:" << std::endl;
            std::cout << theController->showGroupsList() << std::endl;
            std::cout << "Type number of group you want to delete" << std::endl;
            std::cin >> nrToDelete;
            while (checkIntNumber(nrToDelete, 1, theController->getGroupsCount()) == -1) {
                cout << "Type group number properly\n";
            }
        }
        catch (std::exception e)
        {
        }
        try
        {
            theController->deleteGroup(checkIntNumber(nrToDelete) - 1);
        }
        catch (std::exception e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "There is no group created." << std::endl;
    }
}
// *This method performs interaction with user (via console) during task editing process 
//     * and sends controller task-edit request 
//     *
void View::editTask()
{
    if (theController->getTasksCount() != 0)
    {
        int nrToEdit = 0;
        try
        {
            std::cout << "Type number of task you want to edit" << std::endl;
            std::cin >> nrToEdit;
        }
        catch (std::exception e)
        {
        }
        std::cout << "You\'re editing task: \n" + theController->showTask(nrToEdit - 1) << std::endl;
        std::cout << "Type new taks title or press s to skip" << std::endl;
        std::string newTaskTitle = "";
        
        std::cin >> newTaskTitle;
        if(newTaskTitle!="s") theController->changeTaskTitle(nrToEdit - 1, newTaskTitle);

        std::cout << "Type new taks details or press s to skip" << std::endl;
        std::string newTaskDetails = "";

        std::cin >> newTaskDetails;
        if(newTaskDetails!="s")theController->changeTaskDetails(nrToEdit - 1, newTaskDetails);

        cout << "Type number of day you want to do this task or press s to skip editing \n";
        string taskDeadline = "";
        cin >> taskDeadline;

        int deadlineInt;  //checkIntNumber(taskDeadline);
        if (!taskDeadline.empty() && taskDeadline!="s") {

            //struct tm taskDeadlineTm = theDataBase->getTaskDeadline();
            deadlineInt = checkIntNumber(taskDeadline);
            if (deadlineInt != -1) {
                theController->changeTaskDeadline((theController->getTasksCount() - 1), deadlineInt);
            }
            else {
                cout << "You haven't typed date of deadline in way this program can recognize. Try again\n";
                cin >> taskDeadline;
                deadlineInt = checkIntNumber(taskDeadline);
                if (taskDeadline == "" || deadlineInt == -1) {
                    cout << "You haven't typed date of deadline in way this program can recognize. Deadline not changed";
                }
                else {
                    theController->changeTaskDeadline((theController->getTasksCount() - 1), deadlineInt);
                }
            }
        }

        //Group
        if (theController->getGroupsCount() != 0)
        {
            std::cout << "Do you want to change this task's group? n / y \n" << std::endl;
            std::string answer = "";
            std::cin >> answer;
            bool decided = false;
            while (!decided)
            {
                if (answer == "n" || answer == "N")
                {
                    decided = true;
                }
                else if (answer == "y" || answer == "Y")
                {
                    decided = true;
                    std::cout << "Avaible groups: " + theController->showGroupsList() << std::endl;
                    std::cout << "Please press group number" << std::endl;
                    int groupNr = 0;
                    std::cin >> groupNr;
                    try
                    {
                        //theController->addTask(newTaskTitle, groupNr - 1);
                        theController->changeTaskGroup((theController->getTasksCount() - 1), groupNr - 1);
                    }
                    catch (std::exception e)
                    {
                    }
                }
                else
                {
                    std::cout << "You need to press y or n" << std::endl;
                }
            }
        }

        std::cout << "Do you want to change this task's mood? n / y \n" << std::endl;
        std::string answer = "";
        std::cin >> answer;
        bool decided = false;
        while (!decided)
        {
            if (answer == "n" || answer == "N") decided = true;
            else if (answer == "y" || answer == "Y")
            {
                decided = true;
                std::cout << "Avaible moods: " + theController->showMoodsList() << std::endl;
                std::cout << "Please press mood number" << std::endl;
                int moodNr = 0;
                std::cin >> moodNr;
                try
                {
                    theController->changeTaskMood((theController->getTasksCount() - 1), moodNr - 1);
                }
                catch (std::exception e)
                {
                }
            }
            else
            {
                std::cout << "You need to press y or n" << std::endl;
            }
        }

        std::cout << "Task: " << theController->showTasksTitle((theController->getTasksCount() - 1)) << " edited successfully!" << std::endl;



    }
    else
    {
        std::cout << "The task\'s list is empty" << std::endl;
    }
}
// *This method performs interaction with user (via console) during task editing process 
//     * and sends controller task-edit request 
//     *
void View::editGroup()
{
    if (theController->getGroupsCount() != 0)
    {
        int nrToEdit = 0;
        std::cout << "Avaible groups: " + theController->showGroupsList() << std::endl;
        std::cout << "Type number of group you want to edit" << std::endl;
        std::cin >> nrToEdit;
        
        std::cout << "You\'re editing group: " + theController->showGroupName(nrToEdit - 1) << std::endl;
        std::cout << "Type new group\'s name" << std::endl;
        std::string newGroupName = "";
        std::cin >> newGroupName;
        
        theController->changeGroupName(nrToEdit - 1, newGroupName);
    }
    else
    {
        std::cout << "There is no group created." << std::endl;
    }
}
// *This method asks user for data in console and sends controller task-delete request 
//     *
void View::deleteTask()
{
    if (theController->getTasksCount() != 0)
    {
        string nrToDelete;
        int nrToDeleteInt = -1;
        try
        {
            std::cout << theController->showTasksList() << "\nType number of task you want to delete" << std::endl;
            std::cin >> nrToDelete;
            nrToDeleteInt= checkIntNumber(nrToDelete);
        }
        catch (std::exception e)
        {
        }
        try
        {
            theController->deleteTask(nrToDeleteInt - 1);
        }
        catch (std::exception e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << "The task\'s list is empty" << std::endl;
    }
}
void View::recommendTask()
{
    cout << "In what mood are you now? Chose one by pressing number! \n List of defined moods: " << theController->showMoodsList() << endl;
    int index;
    string number;
    cin >> number;
    //index = checkIntegerNumber(number);//jak nie znajdzie ma zwracaæ -1 i wywalaæ komunikat o b³êdzie(cout), zaimplementowaæ w ViewHelper
    index = checkIntNumber(number, 1, theController->getMoodsCount());

    while (index == -1) {
        cout << "Wrong number, try again\n";
        cin >> number;
        index = checkIntNumber(number, 1, theController->getMoodsCount()); //ma byæ w ViewHelper i zwracaæ -1 albo 1000000000 jak nie ma indexu i wywalaæ komunikat o b³ezie (cout)
        index = checkActionNumber(number); //CHWILOWE
    }

    theController->recommend(index-1); 
}

void View::manageMoods()
{
    string menuMessage = "To define new mood press 1 \nTo edit existing mood name or rating press 2 \nTo delete one of mood press 3\n";
    cout << "List of defined moods: " << theController->showMoodsList() << endl;
    cout << menuMessage;

    string userInput;
    std::cin >> userInput;
    int eventNr = checkActionNumber(userInput);

    string name, number;
    double rating=-1;
    int index=-1;

    switch (eventNr) {
    case 1:
        cout << "Please type name of definded mood\n";
        cin >> name;
        cout << "Please type number which rate these mood, range from 0 (disaster) to 5 (time of your life)\n";
        cin >> number;
        rating = checkFloatingPointNumber(number, 0.0, 5.0); //jak nie znajdzie ma zwracaæ -1 i wywalaæ komunikat o b³êdzie(cout), zaimplementowaæ w ViewHelper
        if (rating != -1) {
            theController->addMood(name, rating);
            cout << "New mood was added successfully. Actualized mood list: " << theController->showMoodsList() << endl;
        }
        break;
    case 2:
        cout << "Please type number of mood you want to edite\n";
        cin >> number;
        //index = checkIntegerNumber(number); //ma byæ w ViewHelper i zwracaæ -1 albo 1000000000 jak nie ma indexu i wywalaæ komunikat o b³ezie (cout)
        index = checkActionNumber(number); //CHWILOWE
        while (index == -1) {
            cout << "Wrong number, try again\n";
            cin >> number;
            //index = checkIntegerNumber(number); //ma byæ w ViewHelper i zwracaæ -1 albo 1000000000 jak nie ma indexu i wywalaæ komunikat o b³ezie (cout)
            index = checkActionNumber(number); //CHWILOWE
        }
        if (index != -1) {
            index--;
            cout << "You chosen " << theController->showMood(index) << endl;

            cout << "Type new name or press s to skip\n";
            name = "";
            cin >> name;
            //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (name != "s") theController->changeMoodName(index, name);

            cout << "Type new rating or press s to skip\n";
            number = "";
            cin >> number;
            if (number != "s") {
                rating = checkFloatingPointNumber(number, 0.0, 5.0); //jak nie znajdzie ma zwracaæ -1 i wywalaæ komunikat o b³êdzie(cout), zaimplementowaæ w ViewHelper
                if (rating != -1) {
                    theController->changeMoodRating(index, rating);
                }
            }
            cout << "Actualized mood: " << theController->showMood(index) << endl;
        }
        break;
    case 3:
        cout << "Please type number of mood you want to delete\n";
        cin >> number;
        //index = checkIntegerNumber(number);//jak nie znajdzie ma zwracaæ -1 i wywalaæ komunikat o b³êdzie(cout), zaimplementowaæ w ViewHelper
        index = checkActionNumber(number); //CHWILOWE

        while (index == -1) {
            cout << "Wrong number, try again\n";
            cin >> number;
            //index = checkIntegerNumber(number); //ma byæ w ViewHelper i zwracaæ -1 albo 1000000000 jak nie ma indexu i wywalaæ komunikat o b³ezie (cout)
            index = checkActionNumber(number); //CHWILOWE
        }

        if (index != -1) {
            index--;
            theController->deleteMood(index);
            cout << "Mood was deleteded successfully. Actualized mood list: " << theController->showMoodsList() << endl;
        }
        break;

    }
}

// *This method shows errorMessage
//     * @param errorMessage
void View::showError(std::string errorMessage)
{
    std::cout << errorMessage << std::endl;
}

// *This method coordinates menu actions and returns informetion about exit request
//     * @return  isExit
bool View::coordinateMenu()
{
    showMenu(theUserController->getUserName());
    bool isExit = false;
    string userInput;
    std::cin >> userInput;
    Action action = Action(checkActionNumber(userInput));

    switch (action) {
    case SHOW_LIST:
        showTasksList();
        break;
    case ADD_TASK:
        addTask();
        break;
    case ADD_GROUP:
        addGroup();
        break;
    case EDIT_TASK:
        editTask();
        break;
    case EDIT_GROUP:
        editGroup();
        break;
    case DELETE_TASK:
        deleteTask();
        break;
    case DELETE_GROUP:
        deleteGroup();
        break;
    case RECCOMEND_TASK:
        recommendTask();
        break;
    case MANAGE_MOODS:
        manageMoods();
        break;
    case EXIT: 
        isExit = true;
        break;
    case INCORRECT: //10th option in Action enum
        showError("Type correct action number");
    default:
        showError("An undefined error occured");
    }
    return isExit;
}

void View::showDisplay()
{
    FileController theFileController;
    string userName = askUserForName();
    theFileController.downloadDataFromFile(userName, theController);

    theUserController->setUserName(userName);
    bool isExitPressed = false;
    while (!isExitPressed)
    {
        isExitPressed = coordinateMenu();
    }
    theFileController.saveDataToFile(userName, theController);
}
// *In case of argument given this is the main method of view
//     *@param userName
void View::showDisplay(std::string userName)
{
    theUserController->setUserName(userName);
    bool isExitPressed = false;
    while (!isExitPressed)
    {
        isExitPressed = coordinateMenu();
    }
    theController->clearMemory();
    delete theController;
}


void View::clearMemory() {
    theController->clearMemory();
    delete theController;
}