#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}


// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}


// Operators
Animal & Animal::operator=(const Animal &assign)
{
	(void) assign;
	return (*this);
}

// Getters
std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::string	sound;

	if (getType() == "Cat")
		sound = "Meow";
	else if (getType() == "Dog")
		sound = "Woof";
	else
		sound = "";
	std::cout << sound << std::endl;
}