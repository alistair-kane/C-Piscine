#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
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
	// std::copy(assign.getIdeas(), assign.getIdeas() + 100, this->ideas);
	*this = assign;
	return (*this);
}

const std::string* Brain::getIdeas(void) const
{
	return (this->ideas);
}

void Brain::setIdeas(const std::string* ideas)
{
	std::copy(ideas, ideas + 100, this->ideas);
}