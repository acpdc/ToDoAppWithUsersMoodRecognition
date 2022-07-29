#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <string>
#include "Group.h"
#include "Controller.h"
#include "DataBase.h"
#include "View.h"
#include "WrongIndexException.h"
#include <crtdbg.h>

class Settlement {
public:
    // returns a value of standard input in c++
    template < typename T > static T input() {
        T value;
        std::cin >> value;
        return value;
    }
};

int main()
{
    View* view = new View();
    view->showDisplay();
    view->clearMemory();
    delete view;
    _CrtDumpMemoryLeaks();
    return 0;
}
