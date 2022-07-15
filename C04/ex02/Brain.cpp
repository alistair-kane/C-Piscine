#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{	
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}

// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

// Operators
Brain & Brain::operator=(const Brain &assign)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = assign.ideas[i];
	return (*this);
}

const std::string Brain::getIdeas(unsigned int index) const
{
	if (index < 100)
		return (this->ideas[index]);
	return ("");
}

void Brain::setIdeas(unsigned int index, const std::string idea)
{
	if (index < 100)
		this->ideas[index] = idea;
}