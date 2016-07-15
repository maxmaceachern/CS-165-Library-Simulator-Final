#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>
#include "LibraryItem.hpp"

class Album :public LibraryItem
{
public:
	static const int CHECK_OUT_LENGTH = 14;
	Album(std::string, std::string, std::string);
	std::string getArtist();
	int getCheckOutLength();

private:
	std::string artist;
};

#endif


