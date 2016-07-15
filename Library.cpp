#include "Library.hpp"
#include <string>
#include <vector>
#include "Book.hpp"
#include "Album.hpp"
#include "Movie.hpp"
#include "Patron.hpp"

using namespace std;
/***************************************************
*        Library Class Default Constructor
* ************************************************/
Library::Library()
{
	currentDate = 0;
}

/***************************************************
*             Library Class Destructor
* ************************************************/
Library::~Library()
{
	for (int patron = 0; patron < (members.size()); patron++)
	{
		delete members[patron];
	}

	for (int item = 0; item < (holdings.size()); item++)
	{
		delete holdings[item];
	}
}




/***************************************************
*               addLibraryItem
* -add LibraryItem* item to holdings vector
* ************************************************/
void Library::addLibraryItem(LibraryItem* l)
{
	holdings.push_back(l);
}

/***************************************************
*               addPatron
* adds Patron* member to members vector
* ************************************************/
void Library::addPatron(Patron* p)
{
	members.push_back(p);
}


/***************************************************
*               checkOutLibraryItem
*  input validation used
*  updates holding and patron info to simulate
*  a successful checked out of an item by a
*  patron of the library
* ************************************************/
std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID)
{
	LibraryItem* holding = getLibraryItem(ItemID);
	Patron* member = getPatron(patronID);

	if (holding == NULL)
		return "item not found";
	else if (getPatron(patronID) == NULL)
		return "patron not found";

	if (holding->getLocation() == CHECKED_OUT)
		return "item already checked out";

	if (holding->getRequestedBy() != NULL) {
		Patron* holder = holding->getRequestedBy();
		if ((holding->getLocation() == ON_HOLD_SHELF) && (holder->getIdNum() != patronID))
			return "item on hold by other patron";
	}
	
	holding->setCheckedOutBy(getPatron(patronID));
	holding->setDateCheckedOut(currentDate);
	holding->setLocation(CHECKED_OUT);
	
	if ((holding->getRequestedBy()) != NULL)
	{
		Patron* holder = holding->getRequestedBy();
		if (holder->getIdNum() == patronID)
		{
			holding->setRequestedBy(NULL);
		}
	}

	member->addLibraryItem(holding);
	return "check out successful";
	
}

/***************************************************
*               returnLibraryItem
*  input validation used
*  updates holding and patron info to simulate
*  a successful return of an item by a patron
* ************************************************/
std::string Library::returnLibraryItem(std::string ItemID)
{
	LibraryItem* holding = getLibraryItem(ItemID);

	if (holding == NULL)
		return "item not found";
	if (holding->getLocation() != CHECKED_OUT)
		return "item not checked out";

	Patron* member = holding->getCheckedOutBy();
	//Update Patron's list.
	member->removeLibraryItem(holding);

	//Update LibraryItem's location.
	if ((holding->getRequestedBy()) != NULL)
	{
		holding->setLocation(ON_HOLD_SHELF);
	}
	else
	{
		holding->setLocation(ON_SHELF);
	}

	//Update checkedOutBy.
	holding->setCheckedOutBy(NULL);

	return "return successful";

}

/***************************************************
*               requestLibraryItem
*  input validation used updates holding
*  and patron info to simulate a successful
*  request for a holding by a patron
* ************************************************/
std::string Library::requestLibraryItem(std::string patronID, std::string ItemID)
{
	LibraryItem* holding = getLibraryItem(ItemID);
	Patron* member = getPatron(patronID);

	if (holding == NULL)
		return "item not found";

	else if (member == NULL)
		return "patron not found";

	if (holding->getRequestedBy() != NULL)
		return "item already on hold";

	holding->setRequestedBy(member);
	if (holding->getLocation() == ON_SHELF)
		holding->setLocation(ON_HOLD_SHELF);
	return "request successful";
}

/***************************************************
*               payFine
*  input validation used.
*  amendFine for user to pay fine
* ************************************************/
std::string Library::payFine(std::string patronID, double payment)
{
	if (getPatron(patronID) == NULL)
		return "patron not found";
	getPatron(patronID)->amendFine(-payment);
	return "payment successful";
}


/***************************************************
*               incrementCurrentDate
*  increment currentDate by one
*  determine for each patron for each of the
*  checkedOutItems if item is overdue.
*  if overdue, use amendFine to add .10 to fine
* ************************************************/
void Library::incrementCurrentDate()
{
	currentDate++;
	
	for (int patron = 0; patron < (members.size()); patron++)
	{
		vector<LibraryItem*> payment = members[patron]->getCheckedOutItems();
		for (int items = 0; items < (payment.size()); items++)
		{
			//Determine if overdue
			LibraryItem* checked = payment[items];

			int days_checked_out = currentDate - (checked->getDateCheckedOut());
			int days_left = (checked->getCheckOutLength()) - days_checked_out;

			if (days_checked_out >(checked->getCheckOutLength()))
			{
				members[patron]->amendFine(.10);
			}
		}
	}
}

Patron* Library::getPatron(std::string patronID)
{
	int size = members.size();
	for (int index = 0; index < size; index++)
	{
		if ((members[index]->getIdNum()) == patronID)
		{
			return members[index];
		}
	}

	return NULL;
}

LibraryItem* Library::getLibraryItem(std::string ItemID)
{
	
	int size = holdings.size();
	for (int index = 0; index < size; index++)
	{
		if ((holdings[index]->getIdCode()) == ItemID)
		{
			return holdings[index];
		}
	}

	return NULL;
}