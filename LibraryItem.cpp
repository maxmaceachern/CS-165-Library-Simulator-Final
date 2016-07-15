#include "LibraryItem.hpp"
#include <string>

/*************************************************
*     LibraryItem Class Constructor
* **********************************************/
LibraryItem::LibraryItem(std::string idc, std::string t)
{
	idCode = idc;
	title = t;
	checkedOutBy = NULL;
	requestedBy = NULL;
	location = ON_SHELF;
}

/*************************************************
*    LibraryItem Class Get Method for idCode
* **********************************************/
std::string LibraryItem::getIdCode()
{
	return idCode;
}

/*************************************************
*    LibraryItem Class Get Method for Title
* **********************************************/
std::string LibraryItem::getTitle()
{
	return title;
}

/*************************************************
*    LibraryItem Class Get Method for Location
* **********************************************/
Locale LibraryItem::getLocation()
{
	return location;
}

/*************************************************
*    LibraryItem Class Set Method for Location
* **********************************************/
void LibraryItem::setLocation(Locale l)
{
	location = l;
}

/*************************************************
*    LibraryItem Class Get Method for checkedOutBy
* **********************************************/
Patron* LibraryItem::getCheckedOutBy()
{
	return checkedOutBy;
}

/*************************************************
*    LibraryItem Class Set Method for checkedOutBy
* **********************************************/
void LibraryItem::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

/*************************************************
*    LibraryItem Class Get Method for requestedBy
* **********************************************/
Patron* LibraryItem::getRequestedBy()
{
	return requestedBy;
}

/*************************************************
*    LibraryItem Class Set Method for requestedBy
* **********************************************/
void LibraryItem::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

/*************************************************
*    LibraryItem Class Get Method for dateCheckedOut
* **********************************************/
int LibraryItem::getDateCheckedOut()
{
	return dateCheckedOut;
}

/*************************************************
*    LibraryItem Class Set Method for dateCheckedOut
* **********************************************/
void LibraryItem::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}