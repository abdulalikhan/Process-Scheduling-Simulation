#pragma once
#include <stdexcept>

class OutOfBoundsException: public std::exception{
	public:
		const char* what() const throw();
};

