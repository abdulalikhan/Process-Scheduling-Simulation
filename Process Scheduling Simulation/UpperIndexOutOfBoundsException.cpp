#include "StdAfx.h"
#include "UpperIndexOutOfBoundsException.h"

const char* UpperIndexOutOfBoundsException::what() const throw(){
	return "Upper Array Index out of bounds!";
}