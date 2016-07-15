#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include "LibraryItem.hpp"

class Movie:public LibraryItem
{
public:
	static const int CHECK_OUT_LENGTH = 7;
	std::string getDirector();
	int getCheckOutLength();
	Movie(std::string, std::string, std::string);

private:

	std::string director;
};

#endif

