#include "Mood.h"

void Mood::setName(string _name)
{
	this->name = _name;
}

void Mood::setRating(double _rating)
{
		this->rating = _rating;
	
}

string Mood::getName()
{
	return this->name;
}

double Mood::getRating()
{
	return this->rating;
}



string Mood::streamToFile()
{
	string content = this->getName() + "\n" + to_string(this->getRating())+"\n";
	return content;
}

Item* Mood::straemFromFile(fstream& fileStream) {
	string name, rating = "";
	fileStream >> name;
	if (name == "ENDOFFILE") return nullptr;
	fileStream>>rating;
	Mood* mood = new Mood(name, stod(rating));
	return mood;
}

Item* Mood::get(Item* itemToAdd)
{
	return itemToAdd;
}

char Mood::whoAmI()
{
	return 'm';
}


