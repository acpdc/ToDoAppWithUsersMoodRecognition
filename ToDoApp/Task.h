#pragma once
#include <string>
#include "Group.h"
#include "Mood.h"
#include "User.h"
#include<regex>
#include<ctime>


enum Status {
    TO_DO,
    IN_PROGRESS,
    DONE
};

class Task: public Item {
private:
    // *the title of the task
    std::string title;
    // *the details of the task
    std::string details;
    Status status;
    Mood* mood;
    tm date, deadline;
    // *the name of task's group
    Group* group;  
    
public:
    std::string getTitle();
    Group* getGroup();
    // * This method gets group's color
    //     * 
    //     * @return color
    std::string getDetails();

   // std::string getCreator();

    static tm todaysDate() {
        struct tm newtime;
        time_t now = time(0);
        localtime_s(&newtime, &now);
        return newtime;
    }

    static tm weekLaterDate() {
        struct tm newtime;
        time_t now = time(0);
        localtime_s(&newtime, &now);
        newtime.tm_wday += 7;;
        return newtime;
    }

    Task(): 
      title(""),
      details(""),
      status(Status::TO_DO),
      mood(nullptr),
      group(nullptr) 
    {
        this->date = todaysDate();
        this->deadline = weekLaterDate();
    };

    Task(std::string _title="", std::string _details="", Mood* _mood=nullptr, Group* _group = nullptr, 
        Status _status = TO_DO, tm _date = todaysDate(), tm _deadline = weekLaterDate()) :
      title(_title),
      group(_group),
      details(_details),
      status(_status),
      mood(_mood),
      date(_date),
      deadline(_deadline)
    {};


    // * This method sets group's name
    //     * 
    //     * @param name
    void setTitle(std::string title);
    // * This method sets group's priority
    //     * 
    //     * @param priority
    void setDetails(std::string priority);
    void setMood(Mood* _mood);
    void setDeadline(tm _dedaline);
    void setStatus(Status _status);
    void setGroup(Group* group);

    std::string getGroupName();
    Mood* getMood();
    tm getDate();
    tm getDeadline();

    
    string tmToString(tm date);
    tm stringToTm(string date);

    virtual string streamToFile();
    virtual Item* straemFromFile(fstream& fileStream);
    virtual Item* get(Item* itemToAdd);
    virtual char whoAmI();
    virtual void streamToConsole() {};

    void clearMemory();
};