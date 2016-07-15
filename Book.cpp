#include "Book.hpp"
#include <string>

/*************************************************
*       Book class Constructor
* **********************************************/
Book::Book(std::string idc, std::string t, std::string a) : LibraryItem(idc, t)
{
	author = a;
}

/*************************************************
*       Book class Get Author Method
* **********************************************/
std::string Book::getAuthor()
{
	return author;
}

/*************************************************
*      Book class Get method for Check Out
* **********************************************/
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}