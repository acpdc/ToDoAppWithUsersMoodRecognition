#include "Task.h"
#include "Mood.h"
#include "Group.h"
// * This class is used to store data about tasks - fundametal units of application TODO
// * A task is a "to-do" element
// * Class Task is part of the model in MVC design pattern.
// * 
// * @author kamila
// * @version 1.1
#include <string>

    // // *constructs empty Task object
    // Task::Task()
    // {
    //     this->title = "";
    //     this->group = new Group();
    //     this->details = "";
    //     this->creator = "";
    // }
    // // *constructs Task object with new title
    // //     * @param newTitle
    // Task::Task(std::string newTitle)
    // {
    //     this->title = newTitle;
    //     this->group = new Group();
    //     this->details = "";
    //     this->creator = "";
    // }
    // // *constructs Task object with new title and details
    // //     * @param newTitle
    // //     * @param newCreator
    // Task::Task(std::string newTitle, std::string newCreator)
    // {
    //     this->title = newTitle;
    //     this->creator = newCreator;
    //     this->details = "";
    //     this->group = new Group();
    // }
    // // *constructs Task object with new title and group
    // //     * @param title
    // //     * @param group
    // Task::Task(std::string title, Group* group)
    // {
    //     this->title = title;
    //     this->group = group;
    //     this->details = "";
    //     this->creator = "";
    // }
    // // *constructs Task object with new title and details
    // //     * @param newTitle
    // //     * @param newDetails
    // //     * @param newCreator
    // Task::Task(std::string newTitle, std::string newDetails, std::string newCreator)
    // {
    //     this->title = newTitle;
    //     this->details = newDetails;
    //     this->creator = newCreator;
    //     this->group = new Group();
    // }
    // // *constructs Task object with new title, group and creator
    // //     * @param title
    // //     * @param group
    // //     * @param creator
    // Task::Task(std::string title, Group* group, std::string creator)
    // {
    //     this->title = title;
    //     this->group = group;
    //     this->creator = creator;
    //     this->details = "";
    // }
    // // *constructs Task object with new title and details
    // //     * @param title
    // //     * @param group
    // //     * @param details
    // //     * @param creator
    // Task::Task(std::string title, Group* group, std::string details, std::string creator)
    // {
    //     this->title = title;
    //     this->group = group;
    //     this->details = details;
    //     this->creator = creator;
    // }
    // *This method returns title
    //     * @return title


    std::string Task::getTitle()
    {
        return title;
    }
    // *This method sets title with newTitle value
    //     * @param newTitle
    void Task::setTitle(std::string newTitle)
    {
        this->title = newTitle;
    }
    // *This method returns task's group
    //     * @return group
    Group* Task::getGroup()
    {
        return group;
    }
    // *This method returns task's group name
    //     * @return group.name
    std::string Task::getGroupName()
    {
        return group->getName();
    }
    Mood* Task::getMood()
    {
        return this->mood;
    }
    tm Task::getDate()
    {
        return this->date;
    }
    tm Task::getDeadline()
    {
        return this->deadline;
    }
    // *This method sets group's name with group value
    //     * 
    //     * @param group
    void Task::setGroup(Group* _group)
    {
        this->group = _group;
    }
    // *This method returns details
    //     * @return deatils
    std::string Task::getDetails()
    {
        return details;
    }
    // *This method sets details
    //     * @param details
    void Task::setDetails(std::string details)
    {
        this->details = details;
    }

    void Task::setMood(Mood* _mood) {
        this->mood = _mood;
    }
    void Task::setDeadline(tm _deadline) {
        this->deadline = _deadline;
    }
    void Task::setStatus(Status _status) {
        this->status = _status;
    }


    void Task::clearMemory() {
        if(group)
            delete group;
    }

    string Task::streamToFile()
    {
        string content = this->getTitle() + "\n" + this->getDetails()+"\n";
        content += this->getMood()->getName() + "\n" + to_string(this->getMood()->getRating()) + "\n";
        content += this->getGroup()->getName() + "\n" + to_string(this->getGroup()->getPriority())+ "\n";
        content += to_string(this->status) + "\n";
        content += tmToString(this->getDate()) + "\n" + tmToString(this->getDeadline()) + "\n";
        return content;
    }

    string Task::tmToString(tm date)
    {
        string output = "";
        output = to_string(date.tm_mday) + "." + to_string(date.tm_mon + 1) + "." + to_string(date.tm_year+1900)+" ";
        return output;
    }

    tm Task::stringToTm(string date) {
        tm foundTm;
        int id = 0, day=0, month=0, year=0;

        while(date[id] != '.') {
            day += atoi(&date[id]);
            id++;
        }

        for (id++; date[id] != '.'; id++) month += atoi(&date[id]);

        month--;

        for (id++; id < date.length(); id++)year += atoi(&date[id]);
        
        foundTm.tm_year = year;
        foundTm.tm_mday = day;
        foundTm.tm_mon = month;

        return foundTm;
    }

    Item* Task::straemFromFile(fstream& fileStream)
    {
        string title, details, moodName, moodRating, groupName, groupPriority, statusStr, date, deadline;
        fileStream >> title;
        if (title == "ENDOFFILE") return nullptr;
        fileStream >> details >> moodName >> moodRating >> groupName >> groupPriority >> statusStr >> date >> deadline;

        Status status;
        if (statusStr == "DONE") status = Status::DONE;
        else if (statusStr == "IN_PROGRES") status = Status::IN_PROGRESS;
        else status = Status::TO_DO;

        Mood* mood = new Mood(moodName, stod(moodRating));
        Group* group = new Group(groupName, groupPriority);
        Task* task = new Task(title, details, mood, group, status, stringToTm(date), stringToTm(deadline));
        return task;
    }

    Item* Task::get(Item* itemToAdd)
    {
        return itemToAdd;
    }
    char Task::whoAmI() {
        return 't';
    }