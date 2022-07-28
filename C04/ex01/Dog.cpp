#include "Animal.hpp"
#include "Dog.hpp"

// Constructors
Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal()
{
	this->type = copy.type;
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		brain->setIdeas(i, copy.getIdeas(i));
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}

// Destructor
Dog::~Dog()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}

// Operators
Dog & Dog::operator=(const Dog &assign)
{
	this->type = assign.type;
	for (int i = 0; i < 100; i++)
		brain->setIdeas(i, assign.getIdeas(i));
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

std::string Dog::getIdeas(unsigned int index) const
{
	if (index < 100)
		return(brain->getIdeas(index));
	return ("");
}

void Dog::setIdeas(unsigned int index, const std::string idea) const
{
	if (index < 100)
		return brain->setIdeas(index, idea);
}