#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}

// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	this->type = assign.type;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}