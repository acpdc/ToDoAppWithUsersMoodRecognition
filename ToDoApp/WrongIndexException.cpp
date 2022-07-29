#include "WrongIndexException.h"

WrongIndexException::WrongIndexException(string message)
{
}
// *This is constructor with two - String and intiger - parameters
WrongIndexException::WrongIndexException(string message, int exceptionNumber)
{
    this->exceptionNumber = exceptionNumber;
}
// *This method returns exceptionNumbe
//     * @return exceptionNumber
int WrongIndexException::getExceptionNumber()
{
    return exceptionNumber;
}

const char* WrongIndexException::what() const throw () {
    return "Wrong Index Exception";
}


