#include "DataBase.h"
// *
// * This class collect and groups other model's class.
// * In future it will implements handling with files.
// * 
// * 
// * @version 1.0
// * @author kamila

std::vector<Task*> DataBase::getTasksList()
{
    return theTasksList;
}
// *This method returns theGroupsList
//    * 
//    * @return theGroupsList
std::vector<Group*> DataBase::getGroupsList()
{
    return theGroupsList;
}

std::vector<Mood*> DataBase::getMoodList()
{
    return theMoodList;
}


// *This method returns Task with given id and throws WrongIndexException when given id is not correct
//    * 
//    * @throws WrongIndexException
//    * @param taskIndex
//    * @return theTasksList.get(taskIndex)

Task* DataBase::getTask(int taskIndex) //throws WrongIndexException
{
    if (taskIndex >= theTasksList.size())
    {
        //throw new WrongIndexException("Error during getting: Given index of task is too large", 0);
        return nullptr;
    }
    else
        if (taskIndex < 0)
        {
            cerr<<"Error during getting: Given index of task is wrong";
            return nullptr;
        }
        else
        {
            return theTasksList.at(taskIndex);//theTasksList(taskIndex);
        }
    return nullptr;
}
// *This method returns Group with given id and throws WrongIndexException when given id is not correct
//     * 
//     * @throws WrongIndexException
//     * @param groupIndex
//     * @return theGroupsList.get(groupIndex);
Group* DataBase::getGroup(int groupIndex) //throws WrongIndexException
{
    if (groupIndex >= theGroupsList.size())
    {
        cerr<<"Index is bigger than the group list size";
    }
    else
        if (groupIndex < 0)
        {
            cerr<<"Index is lower than 0";
        }
        else
        {
            return theGroupsList[groupIndex];
        }
    return nullptr;
}

Mood* DataBase::getMood(int moodIndex) //throws WrongIndexException
{
    if (moodIndex >= theMoodList.size())
    {
        cerr << "Index is bigger than the group size";
    }
    else
        if (moodIndex < 0)
        {
            cerr << "Index is lower than 0";
        }
        else
        {
            return theMoodList[moodIndex];
        }
    return nullptr;
}


// *This method returns size of tasks list
//     * 
//     * @return theTasksList.size()
int DataBase::getTasksCount()
{
    return theTasksList.size();
}
// *This method returns size of groups list
//     * 
//     * @return theGroupsList.size()
int DataBase::getGroupsCount()
{
    return theGroupsList.size();
}

int DataBase::getMoodCount()
{
    return theMoodList.size();
}

// *This method adds new task without group to the Tasks List
//     * 
//     * @param taskTitle
//     * @param userName
void DataBase::addTask(std::string taskTitle, string details)
{
    Task* newTask = new Task(taskTitle, details, theMoodList[0], theGroupsList[0]);
    theTasksList.push_back(newTask);
}
void DataBase::addTask(std::string taskTitle)
{
    cout << "PUSTE //**TODO \n";
}
// *This method adds new task with group to the Tasks List and throws WrongIndexException 
//     * when given group id is not correct
//     * 
//     * @throws WrongIndexException
//     * @param taskTitle
//     * @param groupNumber
//     * @param userName
void DataBase::addTask(std::string taskTitle, int groupNumber, int moodNumber, string date, string deadline, string taskDetails = "") //throws WrongIndexException
{
    if (groupNumber >= theGroupsList.size() || groupNumber<0)
    {
        cerr<<"Wrong Index\n";
    }
        else if (moodNumber >= theMoodList.size() || moodNumber < 0)
        {
            cerr << "Wrong index\n";
        }
            else
            {
                Task* newTask = new Task(taskTitle, taskDetails, theMoodList[moodNumber], theGroupsList[groupNumber], Status::TO_DO); //**TO DO : ADD date & deadline
                theTasksList.push_back(newTask);
            }
}

// *This method adds new group to the Groups List
//     * 
//     * @param groupName
void DataBase::addGroup(std::string groupName, Priority groupPriority = Priority::MEDIUM)
{
    Group* newGroup = new Group(groupName, groupPriority);
    theGroupsList.push_back(newGroup);
}

void DataBase::addGroup(std::string groupName, int priorityNumber)
{
    Group* newGroup = new Group(groupName, Priority(priorityNumber));
    theGroupsList.push_back(newGroup);
}

void DataBase::addMood(std::string name, double rating = 2.5)
{
    Mood* newMood = new Mood(name, rating);
    theMoodList.push_back(newMood);
}

// * This method changes title of task with given id and throws WrongIndexException when id is not correct.
//     * 
//     * @throws WrongIndexException
//     * @param taskNr
//     * @param newTitle
void DataBase::changeTaskTitle(int taskNr, std::string newTitle) //throws WrongIndexException
{
    if (taskNr >= theTasksList.size())
    {
        throw new WrongIndexException();
    }
    else
        if (taskNr < 0)
        {
            throw new WrongIndexException();
        }
        else
        {
            theTasksList[taskNr]->setTitle(newTitle);
        }
}
void DataBase::changeTaskDetails(int taskNr, string text)
{
    if (taskNr >= theTasksList.size())
    {
        throw new WrongIndexException();
    }
    else
        if (taskNr < 0)
        {
            throw new WrongIndexException();
        }
        else
        {
            theTasksList[taskNr]->setDetails(text);
        }
}
// * This method changes group of task with given id and throws WrongIndexException 
//     *  when given id is not correct.
//     * 
//     * @throws WrongIndexException
//     * @param taskNr
//     * @param groupNumber
void DataBase::changeTaskGroup(int taskNr, int groupNumber) //throws WrongIndexException
{
    if (groupNumber >= theGroupsList.size())
    {
        throw new WrongIndexException("Error during changing : Given index of group is too large", 8);
    }
    else
        if (groupNumber < 0)
        {
            throw new WrongIndexException("Error during changing : Given index of group is wrong", 9);
        }
        else
            if (taskNr >= theTasksList.size())
            {
                throw new WrongIndexException("Error during changing: Given index of task is too large", 10);
            }
            else
                if (taskNr < 0)
                {
                    throw new WrongIndexException("Error during changing: Given index of group is wrong", 11);
                }
                else
                {
                    theTasksList[taskNr]->setGroup(theGroupsList[groupNumber]);
                }
}

void DataBase::changeTaskMood(int taskNr, int moodNumber) {
    if (moodNumber >= theMoodList.size())
    {
        throw new WrongIndexException("Error during changing : Given index of mood is too large", 8);
    }
    else
        if (moodNumber < 0)
        {
            throw new WrongIndexException("Error during changing : Given index of mood is wrong", 9);
        }
        else
            if (taskNr >= theTasksList.size())
            {
                throw new WrongIndexException("Error during changing: Given index of task is too large", 10);
            }
            else
                if (taskNr < 0)
                {
                    throw new WrongIndexException("Error during changing: Given index of task is wrong", 11);
                }
                else
                {
                    theTasksList[taskNr]->setMood(theMoodList[moodNumber]);
                }
}

void DataBase::changeTaskDeadline(int taskNr, tm deadline) {
    if (taskNr >= theTasksList.size())
    {
        throw new WrongIndexException("Error during changing: Given index of task is too large", 10);
    }
    else
        if (taskNr < 0)
        {
            throw new WrongIndexException("Error during changing: Given index of task is wrong", 11);
        }
        else
        {
            theTasksList[taskNr]->setDeadline(deadline);
        }

}

void DataBase::changeTaskDeadline(int taskNr, int deadline) {
    if (taskNr >= theTasksList.size())
    {
        throw new WrongIndexException("Error during changing: Given index of task is too large", 10);
    }
    else
        if (taskNr < 0)
        {
            throw new WrongIndexException("Error during changing: Given index of task is wrong", 11);
        }
        else
        {
            tm newDeadline = theTasksList[taskNr]->getDate();
            newDeadline.tm_mday += deadline;
            theTasksList[taskNr]->setDeadline(newDeadline);

        }
}

// * This method changes name of group with given id and throws WrongIndexException 
//     * when given id is not correct.
//     * 
//     * @throws WrongIndexException
//     * @param groupNr
//     * @param name
void DataBase::changeGroupName(int groupNr, std::string name) //throws WrongIndexException
{
    if (groupNr >= theGroupsList.size())
    {
        cerr<<"Error during changing: Given index is of group too large";
    }
    else
        if (groupNr < 0)
        {
            cerr<<"Error during changing: Given index of group is wrong";
        }
        else
        {
            theGroupsList[groupNr]->setName(name);
        }
}

void DataBase::changeGroupPriority(int groupNr, int priorityNumber) //throws WrongIndexException
{
    if (groupNr >= theGroupsList.size() || groupNr<0)
    {
        cerr << "Error during changing: Given index is of group wrong\n";
    }
    else
    {
        theGroupsList[groupNr]->setPriority(Priority(priorityNumber));
    }
}

// *This method deletes task from Tasks List and throws WrongIndexException when given id is not correct.
//     * 
//     * @throws WrongIndexException
//     * @param numberToDelete
void DataBase::deleteTask(int numberToDelete) //throws WrongIndexException
{
    if (numberToDelete >= theTasksList.size())
    {
        throw new WrongIndexException("Error during deletion: Given index of task is too large", 14);
    }
    else
        if (numberToDelete < 0)
        {
            throw new WrongIndexException("Error during deletion: Given index of task is wrong", 15);
        }
        else
        {
            delete getTask(numberToDelete);
            theTasksList.erase(theTasksList.begin() + (numberToDelete));
        }
}
// *This method deletes group from Groups List and throws WrongIndexException when given id is not correct
//     * 
//     * @throws WrongIndexException
//     * @param numberToDelete
void DataBase::deleteGroup(int numberToDelete) //throws WrongIndexException
{
    if (numberToDelete >= theGroupsList.size())
    {
        throw;// new WrongIndexException();// "Error during deletion: Given index of group is too large", 16);
    }
    else
        if (numberToDelete < 0)
        {
            throw;// ew WrongIndexException();// "Error during deletion: Given index of group is wrong", 17);
        }
        else
        {
            delete getGroup(numberToDelete);
            theGroupsList.erase(theGroupsList.begin() + (numberToDelete));
        }
}

void DataBase::changeWholeTask(int index, string name, string details, int groupIndex, int moodIndex, string daedline) {
    if (index >= theTasksList.size() || index < 0) cerr << "Wrong task index given\n";
    else  if (groupIndex >= theGroupsList.size() || groupIndex < 0) cerr << "Wrong group index given\n";
    else  if (moodIndex >= theMoodList.size() || moodIndex < 0) cerr << "Wrong mood index given\n";
    else {
        theTasksList[index]->setTitle(name);
        theTasksList[index]->setDetails(details);
        theTasksList[index]->setGroup(theGroupsList[groupIndex]);
        theTasksList[index]->setMood(theMoodList[moodIndex]);
        //theTasksList[index]->setDeadaline(string...to..);

    }
}

void DataBase::changeTaskStatus(int id, Status status) {
    if (id >= theTasksList.size() || id < 0) cerr << "Wrong index given\n";
    else {
        theTasksList[id]->setStatus(status);
    }
}
void DataBase::changeWholeGroup(int index, string name, int priorityNumber) {
    if (index >= theGroupsList.size() || index < 0)
    {
        cerr << "Error during changing: Given index is of group wrong\n";
    }
    else
    {
        theGroupsList[index]->setName(name);
        theGroupsList[index]->setPriority(Priority(priorityNumber));
    }

}
void DataBase::changeWholeMood(int index, string name, double rating) {
    if (index >= theMoodList.size() || index < 0) {
        cerr << "Wrong index given\n";
    }
    else {
        theMoodList[index]->setName(name);
        theMoodList[index]->setRating(rating);
    }
}

void DataBase::changeMoodName(int index, string name) {
    if (index >= theMoodList.size() || index < 0) {
        cerr << "Wrong index given\n";
    }
    else {
        theMoodList[index]->setName(name);
    }
}


void DataBase::changeMoodRating(int index, double rating) {
    if (index >= theMoodList.size() || index < 0) {
        cerr << "Wrong index given\n";
    }
    else {
        theMoodList[index]->setRating(rating);
    }
}

void DataBase::deleteMood(int numberToDelete)
{
    if (numberToDelete >= theMoodList.size())
    {
        cerr<<"Error during deletion: Given index of group is too large\n";
    }
    else
        if (numberToDelete < 0)
        {
            cerr<<"Error during deletion: Given index of group is wrong\n";
        }
        else
        {
            delete getMood(numberToDelete);
            theMoodList.erase(theMoodList.begin() + (numberToDelete));
        }
}



// *This method is clearing list of groups
void DataBase::clearGroupsList()
{
    for (auto group : theGroupsList) {
        delete group;
    }
    theGroupsList.clear();
}
// *This method is clearing list of tasks
void DataBase::clearTasksList()
{
    for (auto task : theTasksList) {
        delete task;
    }
    theTasksList.clear();
}

void DataBase::clearMoodList()
{
    for (auto mood : theMoodList) {
        delete mood;
    }
    theMoodList.clear();
}

// *This method is not implemented yet, but will be used in future to perform stream operation
void DataBase::streamTasksGrouped()
{
}

string DataBase::tmToString(tm date)
{
    string output = "";
    output = to_string(date.tm_mday) + "." + to_string(date.tm_mon+1) + "." + to_string(date.tm_year+1900)+" ";
    return output;
}
