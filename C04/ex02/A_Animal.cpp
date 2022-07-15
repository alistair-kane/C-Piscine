#include "A_Animal.hpp"

// Constructors
A_Animal::A_Animal()
{
	std::cout << "\e[0;33mDefault Constructor called of A_Animal\e[0m" << std::endl;
}

A_Animal::A_Animal(const A_Animal &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of A_Animal\e[0m" << std::endl;
}

// Destructor
A_Animal::~A_Animal()
{
	std::cout << "\e[0;31mDestructor called of A_Animal\e[0m" << std::endl;
}

// Operators
A_Animal & A_Animal::operator=(const A_Animal &assign)
{
	this->type = assign.type;
	return (*this);
}

// Getters
std::string	A_Animal::getType() const
{
	return (this->type);
}

void	A_Animal::makeSound() const
{
	std::cout << "*Generic A_Animal noise*" << std::endl;
}
