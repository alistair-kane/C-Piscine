#include "A_Animal.hpp"
#include "Cat.hpp"

// Constructors
Cat::Cat() : A_Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}

Cat::Cat(const Cat &copy) : A_Animal()
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}

// Destructor
Cat::~Cat()
{
	delete this->brain;
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}

// Operators
Cat & Cat::operator=(const Cat &assign)
{
	for (int i = 0; i < 100; i++)
		brain->setIdeas(i, assign.getIdeas(i));
	return (*this);
}


void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

std::string Cat::getIdeas(unsigned int index) const
{
	if (index < 100)
		return(brain->getIdeas(index));
	return ("");
}

void Cat::setIdeas(unsigned int index, const std::string idea) const
{
	if (index < 100)
		return brain->setIdeas(index, idea);
}