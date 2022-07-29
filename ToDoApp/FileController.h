#pragma once
#include"Controller.h"
#include"UserController.h"
#include "DataBase.h"
#include "Group.h"
#include "Task.h"
#include "User.h"
#include<string>
#include<iostream>
#include <filesystem>
#include "View.h"

struct cntrlString {
	RecommendationController* &controller;
	string fileName;
	char who;
};

class FileController//: public UserController//, public View, public UserController 
{
private:
	UserController* theUserController;
public:
	FileController() {
		this->theUserController = new UserController();
	};
	bool checkOrCreateFilesDirectory();
	string createCustomCategoriesFilling();
	string createCustomMoodsFilling();
	void createEmptyTaskList(string userName);
public:
	void downloadDataFromFile(string userName, RecommendationController*& controller);
	void getItemsListFromFile(cntrlString CS);
	void sendItemsListToFile(RecommendationController*& controller, string fileName, char who);
	//bool getItemsListFromFile(RecommendationController* controller, string fileName);
	//void getItemsListFromFile(cntrlString CS);
	//void sendItemsListToFile(RecommendationController* &controller, string fileName, char who);
	void saveDataToFile(string userName, RecommendationController* &controller);
	
};