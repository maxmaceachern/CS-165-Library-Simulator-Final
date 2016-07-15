#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "LibraryItem.hpp"

class Book :public LibraryItem
{
public:
	static const int CHECK_OUT_LENGTH = 21;
	std::string getAuthor();
	int getCheckOutLength();
	Book(std::string, std::string, std::string);

private:
	std::string author;
};

#endif
