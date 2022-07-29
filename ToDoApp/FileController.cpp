#include "FileController.h"
#include <thread>
#include<future>

bool FileController::checkOrCreateFilesDirectory() {
	return false;
}
mutex mutexgetItemsListFromFileLambda;
auto getItemsListFromFileLambda = [](cntrlString CS) {
	fstream file;
	file.open(CS.fileName);
	bool itemNotNull = true;
	if (file.good() && itemNotNull) {
		while (!file.eof()) {
			mutexgetItemsListFromFileLambda.lock();
			Item* newItem = CS.controller->getItemFromFile(CS.who, file);
			mutexgetItemsListFromFileLambda.unlock();

			mutexgetItemsListFromFileLambda.lock();
			if (newItem != nullptr) CS.controller->addItem(newItem);
			else itemNotNull = false;
			mutexgetItemsListFromFileLambda.unlock();
		}
	}
	else cout << "File " << CS.fileName << "failed to open\n";
	file.close();
};

void FileController::downloadDataFromFile(string userName, RecommendationController*& controller)
{
	//checkAppDirectory; //sprawdza czy jest lub tworzy katalog programu i zwraca œxie¿kê do niego
	//checkUserDirectory(userName); //sprawdza czy jest lub tworzy katalog programu i zwraca œxie¿kê do niego
	//checkUserFile; //sprawdza czy s¹ wszystkie, jak folder pusty: tworzy puste tasks.txt, wype³nia moods.txt i groups.txt default treœciami
	//getItemsFromFile(args: 
	//wskaŸnik na Controller z listami i isnatncj¹ DataBase, filename(tasks, moods, groups), filepath/filestream z odpowiedniej œcie¿ki? 
	//getItemsListFromFile(controller, "groups"); //zamykanie plików po tym wszytkim
	//getItemsListFromFile(controller, "tasks");

	filesystem::path myPath = filesystem::current_path() / "ToDoApp" / userName;
	std::filesystem::path rel_p("Desktop");
	filesystem::create_directories("Desktop/TodDoApp/" + userName);
	filesystem::create_directories(myPath);

	std::ofstream ofsMood(myPath/"moods.txt");
	ofsMood << createCustomMoodsFilling();
	ofsMood.close();
	
	std::ofstream ofsGoup(myPath / "groups.txt");
	ofsGoup << createCustomCategoriesFilling();
	ofsGoup.close();

	std::ofstream ofsTask(myPath / "tasks.txt");
	ofsTask << "";
	ofsTask.close();

	cntrlString CSMood(controller, (myPath / "moods.txt").string(), 'm');
	cntrlString CSGroup = { controller, (myPath / "groups.txt").string(), 'g'};
	cntrlString CSTask = { controller, (myPath / "tasks.txt").string(), 't' };

	std::thread threadGroup(getItemsListFromFileLambda, CSGroup);
	std::thread threadTask(getItemsListFromFileLambda, CSTask);
	std::thread threadMood(getItemsListFromFileLambda, CSMood);

	threadMood.join();
	threadGroup.join();
	threadTask.join();
	
	//getItemsListFromFile(CSMood);
	//getItemsListFromFile(CSTask);
	//getItemsListFromFile(CSGroup);

	//makeDirectoriesAndFilesProperlyClosed();
}

void checkUserFiles() {

}

void FileController::getItemsListFromFile(cntrlString CS) {

	fstream file;
	file.open(CS.fileName);
	bool itemNotNull = true;
	if (file.good() && itemNotNull) {
		while (!file.eof()) {
			Item* newItem = CS.controller->getItemFromFile(CS.who, file);
			if (newItem != nullptr) CS.controller->addItem(newItem);
			else itemNotNull = false;
		}
	}
	else cout << "File " << CS.fileName << "failed to open\n";
	file.close();
}

void FileController::sendItemsListToFile(RecommendationController* &controller, string fileName, char who) {

	fstream file;
	file.open(fileName, ios::trunc);

	if (file.good()) {
		file<< controller->getItemFileFormat(who);
	}
	else cout << "File " << fileName << "failed to open\n";
	file.close();
}

auto sendItemsListToFileLambda = [](cntrlString CS) {

	fstream file;
	file.open(CS.fileName, ios::trunc);

	if (file.good()) {
		file << CS.controller->getItemFileFormat(CS.who);
	}
	else cout << "File " << CS.fileName << "failed to open\n";
	file.close();
};


void FileController::saveDataToFile(string userName, RecommendationController* &controller)
{
	//if (filesToSaveGood()) { //boolowska, daje ok, jak mo¿na zapisywaæ pliki
	filesystem::path myPath = filesystem::current_path() / "ToDoApp" / userName;
		cntrlString CSMood = { controller, (myPath / "moods.txt").string(), 'm' };
		cntrlString CSGroup = { controller, (myPath / "groups.txt").string(), 'g' };
		cntrlString CSTask = { controller, (myPath / "tasks.txt").string(), 't' };
		thread threadMood = thread(sendItemsListToFileLambda, CSMood); //wskaŸnik na Controller z listami i isnatncj¹ DataBase, filename(tasks, moods, groups), filepath/filestream z odpowiedniej œcie¿ki? 
		thread threadGroup = thread(sendItemsListToFileLambda, CSGroup);	// filepath/filestream z odpowiedniej œcie¿ki? (najpierw sendItems.. czyœci pliki moods.txt, gr... i potem wpisuje wszystko na nowo z Controllera i jego "getList.."
		thread threadTask= thread(sendItemsListToFileLambda,CSTask);//zamykania plików po tym wszystkich
		threadMood.join();
		threadGroup.join();
		threadTask.join();
	//	makeDirectoriesAndFilesProperlyClosed();
}

string FileController::createCustomMoodsFilling()
{
	return "tired\n2.0\n"
		"exhausted\n0.5\n"
		"sad\n1.5\n"
		"bored\n3.0\n"
		"concentrated\n4.0\n"
		"enthusiastic\n5.0\n"
		"happy\n4.5\nENDOFFILE";


}

string FileController::createCustomCategoriesFilling()
{
	return "school\nHIGH\n"
		"work\nHIGH\n"
		"hobby\nMEDIUM\n"
		"home\nMEDIUM\n"
		"freeTime\nLOW\nENDOFFILE";

}

void FileController::createEmptyTaskList(string userName)
{
}
