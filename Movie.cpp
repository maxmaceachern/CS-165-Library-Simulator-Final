#include "Movie.hpp"
#include <string>

/*************************************************
*       Movie class Constructor
* **********************************************/
Movie::Movie(std::string idc, std::string t, std::string d) : LibraryItem(idc, t)
{
	director = d;
}

/*************************************************
*       Movie class Get Director Method
* **********************************************/
std::string Movie::getDirector()
{
	return director;
}

/*************************************************
*      Movie class Get method for Check Out
* **********************************************/
int Movie::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}