#pragma once
#include<string>
#include<fstream>
using namespace std;
class Item
{
public:
	virtual string streamToFile() = 0;
	virtual Item* straemFromFile(fstream& fileStream)=0;
	virtual Item* get(Item* itemToAdd) = 0;
	virtual void streamToConsole() = 0;
	virtual char whoAmI() = 0;
};

