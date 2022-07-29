#include "Controller.h"

Controller::Controller()
{
    MoodsAndGroupsController();
}
// *This method returns String with ready to show list of tasks
//     * @return stringBuilder.toString()
std::string Controller::showTasksList()
{
    std::string stringBuilder = "";
    int taskNr = 1;
    for (auto i : theDataBase->getTasksList())
    {
        stringBuilder+=to_string(taskNr);
        taskNr++;
        stringBuilder.append(". ");
        std::string content = i->getTitle();
        stringBuilder.append(content);
        stringBuilder.append("\n");
    }
    return stringBuilder;
}

std::string Controller::showTasksGroupedList()
{
    return std::string();
}

// *This method returns ready-to-show  string with title of task
//     * @param taskNr
//     * @return content
std::string Controller::showTasksTitle(int taskNr)
{
    std::string content = "";
    content = theDataBase->getTask(taskNr)->getTitle();
    return content;
}
// *This method returns ready-to-show string with group of task
//     * @param taskNr
//     * @return content
std::string Controller::showTasksGroup(int taskNr)
{
    std::string content = "";
        content = theDataBase->getTask(taskNr)->getGroup()->getName();
    return content;
}

std::string Controller::showTask(int taskNr)
{
    string content = "";

    content += showTasksTitle(taskNr);
    content += "\n";
    content += theDataBase->getTask(taskNr)->getDetails();
    content += "\n Added: ";
    content += theDataBase->tmToString(theDataBase->getTask(taskNr)->getDate());
    content += theDataBase->tmToString(theDataBase->getTask(taskNr)->getDeadline());
    content += "\n Group: ";
    content += showTasksGroup(taskNr);
    content += " , mood: ";
    content += theDataBase->getTask(taskNr)->getMood()->getName();

    return content;
}

// *This method is not implemented yet, but will be returns map of tasks by given group (using stream operations).
//     * 
//     * @param groupId
void Controller::getTasksFromGroupMap(int groupId)
{
}

// * This method coordinates with Model changing title of task with given id.
//     * 
//     * @param taskNr
//     * @param //**TODO
void Controller::changeTaskTitle(int taskNr, std::string newTitle)
{
        theDataBase->changeTaskTitle(taskNr, newTitle);
}

void Controller::changeTaskDetails(int taskNr, std::string text)
{
    theDataBase->changeTaskDetails(taskNr, text);
}
// * This method coordinates with Model changing group of task with given id.
//     * 
//     * @param taskNr
//     * @param groupNumber
void Controller::changeTaskGroup(int taskNr, int groupNumber)
{
    theDataBase->changeTaskGroup(taskNr, groupNumber);
}

void Controller::changeTaskMood(int taskNr, int moodNr) {
    theDataBase->changeTaskMood(taskNr, moodNr);
}

void Controller::changeTaskDeadline(int taskNr, tm deadline) {
    theDataBase->changeTaskDeadline(taskNr, deadline);
}

void Controller::changeTaskDeadline(int taskNr, int deadline) {
    theDataBase->changeTaskDeadline(taskNr, deadline);
}

// *This method coordinates with Model new task addition without task's group adding
//     * @param taskTitle
void Controller::addTask(std::string taskTitle)
{
         theDataBase->addTask(taskTitle);
}
// *This method coordinates with Model new task addition with task's group adding
//     * @param taskTitle
//     * @param groupNumber
void Controller::addTask(std::string taskTitle, int groupNumber)
{
        //theDataBase->addTask(taskTitle, groupNumber);
    cout << "NOT IMPLEMENTED, from Controller::addTask(std::string taskTitle, int groupNumber) \n";
}

void Controller::addTask(std::string title, std::string details) {
    theDataBase->addTask(title, details);
}

void Controller::addItem(Item* item)
{
    char who = item->whoAmI();
    switch (who) {
    case 'm':
        theDataBase->getMoodList().push_back((Mood*)item);
        //cout << "theDataBase->getMoodList().push_back((Mood*)item);\n";
        break;
    case 't':
        theDataBase->getTasksList().push_back((Task*)item);
        //cout << "theDataBase->getTasksList().push_back((Task*)item);\n";
        break;
    case 'g':
        theDataBase->getGroupsList().push_back((Group*)item);
        //cout << "theDataBase->getGroupsList().push_back((Group*)item);\n";
       // break;
    }
}

Item* Controller::getItemFromFile (char who, fstream& fileStream) {
    //newItem->straemFromFile(file);
    Mood* mood = nullptr;
    Group* group = nullptr;
    Task* task = nullptr;
    Mood* taskMood = nullptr;
    Group* taskGroup = nullptr;
    string title, details, moodName, moodRating, groupName, groupPriority, statusStr, date, deadline;
    string name, rating, namegr,priorityStr = "";
    Status status;
    switch (who) {
    case 'm':
        //cout << "Controller::getItemFromFile, mood beg \n";
        fileStream >> name;
        if (name == "ENDOFFILE") {return nullptr; }
        fileStream >> rating;
        mood = new Mood(name, stod(rating));
        //cout << "Controller::getItemFromFile, mood end2 \n";
        return mood;
    case 't':
        //cout << "Controller::getItemFromFile, task beg \n";
        fileStream >> title;
        if (title == "ENDOFFILE" || title=="") {return nullptr; }
        fileStream >> details >> moodName >> moodRating >> groupName >> groupPriority >> statusStr >> date >> deadline;
        if (statusStr == "DONE") status = Status::DONE;
        else if (statusStr == "IN_PROGRES") status = Status::IN_PROGRESS;
        else status = Status::TO_DO;
        taskMood = new Mood(moodName, stod(moodRating));
        taskGroup = new Group(groupName, groupPriority);
        task = new Task(title, details, taskMood, taskGroup, status, stringToTm(date), stringToTm(deadline));
        //cout << "Controller::getItemFromFile, task end2 \n";
        return task;
    case 'g':
        //cout << "Controller::getItemFromFile, gr beg \n";
       // cout << "g1\n";
        fileStream >> namegr;
        //cout << namegr<<"\n";
        if (namegr == "ENDOFFILE" || namegr=="") {return nullptr; }
        //cout << "g3\n";
        fileStream >> priorityStr;
        //cout << "g4\n";
        group = new Group(namegr, priorityStr);
        //cout << "g5\n";
       // cout << "Controller::getItemFromFile, gr end2 \n";
        //cout << "g6\n";
        return group;
    }
}

string Controller::getItemFileFormat(char who) {

    string result="";
    switch (who) {
    case 'm':
        for(Mood* i : theDataBase->getMoodList()){
            result += i->streamToFile();
        }
        result += "ENDOFFILE";
        break;
    case 't':
        for (Task* i : theDataBase->getTasksList()) {
            result += i->streamToFile();
        }
        result += "ENDOFFILE";
        break;
    case 'g':
        for (Group* i : theDataBase->getGroupsList()) {
            result += i->streamToFile();
        }
        result += "ENDOFFILE";
        break;
    }
    return result;
 }
// *This method coordinates with Model task removal
//     * @param numberToDelete
void Controller::deleteTask(int numberToDelete)
{
        theDataBase->deleteTask(numberToDelete);
}
// *This method returns size of tasks list
//     * 
//     * @return theTasksList.size()
int Controller::getTasksCount()
{
    return theDataBase->getTasksCount();
}

tm Controller::stringToTm(string date) {
    tm foundTm;
    int id = 0, day = 0, month = 0, year = 0;

    while (date[id] != '.') {
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

void Controller::clearMemory() {
    theDataBase->clearTasksList();
    theDataBase->clearGroupsList();
    theDataBase->clearMoodList();
    delete theDataBase;
}