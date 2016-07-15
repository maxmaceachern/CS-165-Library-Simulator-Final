#include "Album.hpp"
#include <string>

/*************************************************
*       Album class Constructor
* **********************************************/
Album::Album(std::string idc, std::string t, std::string a) : LibraryItem(idc, t)
{
	artist = a;
}

/*************************************************
*       Album class Get Artist Method
* **********************************************/
std::string Album::getArtist()
{
	return artist;
}

/*************************************************
*      Album class Get method for Check Out
* **********************************************/
int Album::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}