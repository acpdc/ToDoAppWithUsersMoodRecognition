#pragma once
#include<string>
#include"Item.h" 
    // *This is definition of enum used to set group priority
    enum Priority {
        LOW,
        MEDIUM,
        HIGH
    };

class Group: public Item
{


    std::string name;


    // *This enum contains priority of a group
    Priority priority;

    // *Non-parameter constructor with setting default values of name, priority and color
    //     *
public:
    Group();
    // * One-parameter constructor with setting default values of priority and color
    //     * 
    //     * @param name
    Group(std::string name);
    // * Two-parameters constructor with setting default values color
    //     * 
    //     * @param name
    //     * @param priority
    Group(std::string name, Priority priority);
    Group(std::string name, std::string priority);
    // *This method gets group's name
    //     * 
    //     * @return name
    std::string getName();
    // * This method gets group's priority
    //     * 
    //     * @return priority
    Priority getPriority();
    // * This method sets group's name
    //     * 
    //     * @param name
    void setName(std::string name);
    // * This method sets group's priority
    //     * 
    //     * @param priority
    void setPriority(Priority priority);

    Priority stringToPriority(string priorityStr);

    virtual string streamToFile();
    virtual Item* straemFromFile(fstream& fileStream);
    virtual Item* get(Item* itemToAdd);
    virtual char whoAmI();
    virtual void streamToConsole() {};
};

