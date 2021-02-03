#include "StdAfx.h"
#include "OutOfBoundsException.h"
#include <stdexcept>

const char* OutOfBoundsException::what() const throw(){
	return "Array out of bounds!";
}
