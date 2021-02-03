#include "StdAfx.h"
#include "LowerIndexOutOfBoundsException.h"

const char* LowerIndexOutOfBoundsException::what() const throw(){
	return "Lower Array Index out of bounds!";
}