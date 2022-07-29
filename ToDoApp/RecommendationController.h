#pragma once
#include "Controller.h"
//#include "DataBase.h"
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
using namespace std;


class RecommendationController : public Controller
{   
    //DataBase* theDataBase;

    //RecommendationController(DataBase* _dataBase) {
    //    this->theDataBase=
    //}
    //vector<Task*> propositions;

    class checkTaskPassing;

public:
    RecommendationController() {
       
    }

    bool myComparision(Task* t1, Task* t2);

    void recommend(int moodIndex);
};

