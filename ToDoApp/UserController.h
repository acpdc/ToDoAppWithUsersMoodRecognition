#pragma once
#include "User.h"
#include<string>
using namespace std;
class UserController
{
public:
	User* theUser;
	UserController() {
		this->theUser = new User();
	}
	UserController(string name) {
		this->theUser = new User(name);
	}
	~UserController() {
		delete theUser;
	}

	void setUserName(std::string userName);

	std::string getUserName();

	public:/*
	static string askForPasswordReturnAnswer();
	static bool checUserPasswordMatch();
	static void createNewUserInFile();
	static void logInUser();*/
};

