#include "MoodsAndGroupsController.h"

MoodsAndGroupsController::MoodsAndGroupsController()
{
	this->theDataBase = new DataBase();
}

// *This method returns String with ready to show list of groups
//     * @return stringBuilder.toString()
std::string MoodsAndGroupsController::showGroupsList()
{
    std::string stringBuilder = "";
    int groupNr = 1;
    for (auto i : theDataBase->getGroupsList())
    {
        stringBuilder += to_string(groupNr);
        groupNr++;
        stringBuilder.append(".");
        std::string content = i->getName();
        stringBuilder.append(content);
        stringBuilder.append(" ");
    }
    return stringBuilder;
}

std::string MoodsAndGroupsController::showMoodsList()
{
    std::string stringBuilder = "";
    int nr = 1;
    for (auto i : theDataBase->getMoodList())
    {
        stringBuilder += to_string(nr);
        nr++;
        stringBuilder.append(".");
        std::string content = i->getName();
        stringBuilder.append(content);
        stringBuilder.append("  ");
    }
    return stringBuilder;
}

std::string MoodsAndGroupsController::showGroupName(int groupNr)
{
    std::string name = "";
    name = theDataBase->getGroup(groupNr)->getName();
    return name;
}

std::string MoodsAndGroupsController::showMoodName(int nr)
{
    std::string name = "";
    name = theDataBase->getMood(nr)->getName();
    return name;
}

std::string MoodsAndGroupsController::showMood(int nr)
{
    std::string text = "{ name: ";
    text = theDataBase->getMood(nr)->getName();
    text += ", rating: ";
    text+=to_string(theDataBase->getMood(nr)->getRating());
    text += " }";
    return text;
}

// *This method coordinates with Model group addition
//     * @param groupName
void MoodsAndGroupsController::addGroup(std::string groupName)
{
    theDataBase->addGroup(groupName);
}

void MoodsAndGroupsController::addGroup(std::string groupName, int priorityNumber)
{
    theDataBase->addGroup(groupName, priorityNumber);
}

void MoodsAndGroupsController::addMood(std::string moodName, double rating)
{
    theDataBase->addMood(moodName, rating);
}

// * This method coordinates with Model changing name of group with given id.
//     * 
//     * @param groupNr
//     * @param name
void MoodsAndGroupsController::changeGroupName(int groupNr, std::string name)
{
    theDataBase->changeGroupName(groupNr, name);
}

void MoodsAndGroupsController::changeMoodName(int id, std::string name)
{
    theDataBase->changeMoodName(id, name);
}

void MoodsAndGroupsController::changeMoodRating(int id, double rating)
{
    theDataBase->changeMoodRating(id, rating);
}

// *This method coordinates with Model group removal
//     * @param numberToDelete
void MoodsAndGroupsController::deleteGroup(int numberToDelete)
{
    theDataBase->deleteGroup(numberToDelete);
}

void MoodsAndGroupsController::deleteMood(int id)
{
    theDataBase->deleteMood(id);
}

// *This method returns size of groups list
//     * 
//     * @return theGroupsList.size()
int MoodsAndGroupsController::getGroupsCount()
{
    return theDataBase->getGroupsCount();
}

int MoodsAndGroupsController::getMoodsCount()
{
    return theDataBase->getMoodCount();
}

void MoodsAndGroupsController::clearMemory()
{
    theDataBase->clearGroupsList();
    theDataBase->clearMoodList();
    delete theDataBase;
}

