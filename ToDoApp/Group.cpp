#include "Group.h"
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// *
// *This class is used to store data obout tasks groups.
// * In app user can group tasks 
// * Class Group is part of the model in MVC design pattern.
// * 
// * @author kamila
// * @version 1.0

    Group::Group()
    {
        name = "";
        priority = MEDIUM;
    }
    // * One-parameter constructor with setting default values of priority and color
    //     * 
    //     * @param name
    Group::Group(std::string name)
    {
        this->name = name;
        this->priority = MEDIUM;
    }
    // * Two-parameters constructor with setting default values color
    //     * 
    //     * @param name
    //     * @param priority
    Group::Group(std::string name, Priority priority)
    {
        this->name = name;
        this->priority = priority;
    }
    
    Group::Group(std::string name, std::string priority)
    {
        this->name = name;
        this->priority = stringToPriority(priority);
    }

    // *This method gets group's name
    //     * 
    //     * @return name
    std::string Group::getName()
    {
        return name;
    }
    // * This method gets group's priority
    //     * 
    //     * @return priority
    Priority Group::getPriority()
    {
        return priority;
    }
    // * This method sets group's name
    //     * 
    //     * @param name
    void Group::setName(std::string name)
    {
        this->name = name;
    }
    // * This method sets group's priority
    //     * 
    //     * @param priority
    void Group::setPriority(Priority priority)
    {
        this->priority = priority;
    }
    // * This method sets group's color
    //     * 
    //     * @param color

    Priority Group::stringToPriority(string priorityStr) {

        if (priorityStr == "LOW") return Priority::LOW;
        else if (priorityStr == "HIGH") return Priority::HIGH;
        return Priority::MEDIUM;
    }

    string Group::streamToFile()
    {
        string content = this->getName() + "\n" + to_string(this->getPriority()) +"\n";
        return content;
    }


    Item* Group::straemFromFile(fstream& fileStream) {
        string name, priorityStr ="";
        fileStream << name;
        if (name == "ENDOFFILE") return nullptr;
        fileStream<< priorityStr;
        Group* group = new Group(name, priorityStr);
        return group;
    }

    Item* Group::get(Item* itemToAdd)
    {
        return itemToAdd;
    }

    char Group::whoAmI()
    {
        return 'g';
    }
