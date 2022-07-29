#pragma once
#include<string>
#include<iostream>
#include<regex>
#include<ctime>
using namespace std;

const struct tm EMPTY_TM = { 0 };

class ViewHelper
{
protected:
    ViewHelper();

    // *This method shows menu
    //     * @param username
    void showMenu(std::string username);

    // *This method reads and returns username
    //     * @return username
    //     * TODO - przejmowanie z parametru
    std::string askUserForName();

    int checkActionNumber(string s);
    std::string yesOrNo(string input);

    //**returns -1 or found number
    double checkFloatingPointNumber(string input, double min, double max);
    double checkFloatingPointNumber(string input);

    //**returns -1 or found number
    int checkIntNumber(string input, int min, int max);
    int checkIntNumber(string input);


    // *This method is not implemented yet.
    //     * It should clear the console in future.
    //** convert date to DataBase classe's format from input given by user. Use regex too find these date 
    //tm stringToTm(std::string);
    void clearScreen();


};

