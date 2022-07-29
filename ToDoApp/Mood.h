#pragma once
#include <string>
#include "Item.h"
#include<cmath>
#include<iostream>
using namespace std;
class Mood: public Item
{
private:
	string name;
	double rating;
public:
	Mood():
		name(""),
		rating(0)
	{};
	Mood(string _name = "", double _rating = 0) :
		name(_name),
		rating(_rating)
	{};
	void setName(string name);
	void setRating(double rating);
	string getName();
	double getRating();

	virtual string streamToFile();
	virtual Item* straemFromFile(fstream& fileStream);
	virtual Item* get(Item* itemToAdd);
	virtual char whoAmI();
	virtual void streamToConsole() {};

};

