#pragma once
#include "OutOfBoundsException.h"
/* This is a child exception of the OutOfBoundsException;
It specifically caters for when the Upper Index is out of bounds*/
class UpperIndexOutOfBoundsException: public OutOfBoundsException{
	public:
		// Overiding the what() function
		const char* what() const throw();
};
