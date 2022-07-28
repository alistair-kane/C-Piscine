#include "Animal.hpp"
#include "Cat.hpp"

// Constructors
Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal()
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

// Operators
Cat & Cat::operator=(const Cat &assign)
{
	this->type = assign.type;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}