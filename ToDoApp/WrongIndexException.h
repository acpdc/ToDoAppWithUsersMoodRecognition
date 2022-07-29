#pragma once
#include<string>
using namespace std;
class WrongIndexException : public std::exception
{
    // *This number of exception
private:
    int exceptionNumber;
    // *This is nonparameter constructor
    // *This is constructor with one String parameter
public:
    WrongIndexException(){}
    WrongIndexException(string message);
    // *This is constructor with two - String and intiger - parameters
    WrongIndexException(string message, int exceptionNumber);
    // *This method returns exceptionNumbe
    //     * @return exceptionNumber
    int getExceptionNumber();

    const char* what() const throw ();
};


