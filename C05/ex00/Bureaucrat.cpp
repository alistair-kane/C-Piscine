#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150)
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	_grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat &B)
{
	os << B.getName() << ", bureaucrat grade :" << B.getGrade();
	return (os);
}

// Getters / Setters
const std::string Bureaucrat::getName() const
{
	return _name;
}
unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

// Member functions

void Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

// Exceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high: 1 is maximum";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low: 150 is minimum";
}
