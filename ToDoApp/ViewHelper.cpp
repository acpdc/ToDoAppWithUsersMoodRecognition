#include "ViewHelper.h"

// *This method shows menu
//     * @param username

ViewHelper::ViewHelper()
{
}

void ViewHelper::showMenu(std::string username)
{
    std::cout << "Hello " + username + "!" << std::endl;
    std::cout << "Press 0 to show your task list" << std::endl;
    std::cout << "Press 1 to add new task" << std::endl;
    std::cout << "Press 2 to create new task\'s group" << std::endl;
    std::cout << "Press 3 to edit task" << std::endl;
    std::cout << "Press 4 to edit group" << std::endl;
    std::cout << "Press 5 to delete task" << std::endl;
    std::cout << "Press 6 to delete group" << std::endl;
    std::cout << "Press 7 to get a task recomendation" << std::endl;
    std::cout << "Press 8 to manage moods list" << std::endl;
    std::cout << "Press 9 to exit" << std::endl;
}

string ViewHelper::yesOrNo(string input) {
    regex myRegex1("\\w*(?:y|Y)");
    smatch result1;
    if (regex_search(input, result1, myRegex1)) {
        string s = result1[0];
        return "YES";

    }
    regex myRegex2("\\w*(?:n|N)");
    smatch result2;
    if (regex_search(input, result2, myRegex2)) {
        string s = result2[0];
        return "NO";
    }
    return "NO ANSWER";
}

int ViewHelper::checkActionNumber(string input) {
    regex myRegex("\\d*[0-9]");
    smatch result;
    if (regex_search(input, result, myRegex)) {
        string s = result[0];
        int foundNr = (int)s[0] - 48;
        return foundNr;
    }
    else {
        return 8; //8 - number of error in enum Action
    }
}

double ViewHelper::checkFloatingPointNumber(string input, double min, double max)
{
    regex myRegex("[+-]?((\\d+\\.?\\d*)|(\\.\\d+))");
    smatch result;
    if (regex_search(input, result, myRegex)) {
        string s = result[0];
        double d = stod(s);
        if (d>=min && d<=max) return stod(result[0]);
    }

    cout << "Wrong number given\n";
    return -1;
}

double ViewHelper::checkFloatingPointNumber(string input)
{
    regex myRegex("[+-]?((\\d+\\.?\\d*)|(\\.\\d+))");
    smatch result;
    if (regex_search(input, result, myRegex)) {
        string s = result[0];
        double d = stod(s);

        return  stod(result[0]);
    }

    cout << "Wrong number given\n";
    return -1;
}

int ViewHelper::checkIntNumber(string input, int min, int max)
{
    regex myRegex("\\d*[0-9]");
    smatch result;
    if (regex_search(input, result, myRegex)) {
        string s = result[0];
        int foundNr = (int)s[0] - 48;
        if(foundNr>=min && foundNr<=max) return foundNr;
    }
    return -1;
}

int ViewHelper::checkIntNumber(string input){

    regex myRegex("\\d*[0-9]");
    smatch result;
    if (regex_search(input, result, myRegex)) {
        string s = result[0];
        int foundNr = (int)s[0] - 48;
        return foundNr;
    }
    return -1;
}


// *This method reads and returns username
//     * @return username
//     * TODO - przejmowanie z parametru
std::string ViewHelper::askUserForName()
{
    std::cout << "Type your name" << std::endl;
    std::string userName = "";
    std::cin >> userName;
    return userName;
}

// *This method is not implemented yet.
//     * It should clear the console in future.
void ViewHelper::clearScreen()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "" << std::endl;
    }
}

