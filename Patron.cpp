#include "Patron.hpp"
#include <string>
#include <vector>

/***************************************************
*            Patron Class Constructor
* ************************************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
}

/***************************************************
*       Patron Class Get Method for idNum
* ************************************************/
std::string Patron::getIdNum()
{
	return idNum;
}

/***************************************************
*        Patron Class Get Method for name
* ************************************************/
std::string Patron::getName()
{
	return name;
}

/***************************************************
*   Patron Class Get Method for checkedOutItems
* ************************************************/
std::vector<LibraryItem*> Patron::getCheckedOutItems()
{
	return checkedOutItems;
}

/***************************************************
*          addLibraryItem
* add LibraryItem* b to checkedOutItems vector
* ************************************************/
void Patron::addLibraryItem(LibraryItem* b)
{
	checkedOutItems.push_back(b);
}

/***************************************************
*          removeLibraryItem
*  for checked out items, if the item matches
*  the id code of the item being returned, that
*  item is deleted
* ************************************************/
void Patron::removeLibraryItem(LibraryItem* b)
{
	std::string id;
	id = b->getIdCode();

	int size = checkedOutItems.size();
	for (int i = 0; i < size; i++)
	{
		if ((checkedOutItems[i]->getIdCode()) == id)
		{
			checkedOutItems.erase(checkedOutItems.begin() + i);
			size = i;
		}
	}
}

/***************************************************
*     Patron Class Get Method for fineAmount
* ************************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}

/***************************************************
*          amendFine
* -add amount to fineAmount
* ************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}

