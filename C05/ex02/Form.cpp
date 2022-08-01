#include "Form.hpp"

// Constructors
Form::Form() : _name("Default Name"), _signed(false), _sign_grade(1), _execution_grade(1)
{
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName())
{
	_signed = copy.getSigned();
	_sign_grade = copy.getSign_grade();
	_execution_grade = copy.getExecution_grade();
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const std::string name, unsigned int sign_grade, unsigned int execution_grade) : _name(name)
{
	_signed = false;
	if (sign_grade > 150 || execution_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || execution_grade < 1)
		throw GradeTooHighException();
	_sign_grade = sign_grade;
	_execution_grade = execution_grade;
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form & Form::operator=(const Form &assign)
{
	_signed = assign.getSigned();
	_sign_grade = assign.getSign_grade();
	_execution_grade = assign.getExecution_grade();
	return *this;
}

// Stream operators
std::ostream & operator<<(std::ostream & os, const Form &F)
{
	os << "Name:[" << F.getName() << "]" << std::endl
		<< "Signed?:[" << F.getSigned() << "]" << std::endl
		<< "Sign grade:[" << F.getSign_grade() << "]" << std::endl
		<< "Execution grade:[" << F.getExecution_grade() << "]" << std::endl;
	return os;
}

// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}
bool Form::getSigned() const
{
	return _signed;
}
unsigned int Form::getSign_grade() const
{
	return _sign_grade;
}
unsigned int Form::getExecution_grade() const
{
	return _execution_grade;
}
std::string Form::getTarget() const
{
	return _target;
}

void	Form::setTarget(std::string target)
{
	_target = target;
}

// Member functions
void	Form::beSigned(Bureaucrat &B)
{
	if (_signed == false)
	{
		if (B.getGrade() <= _sign_grade)
			_signed = true;
		else
			std::cout << B.getName() << " has insufficient grade to sign form [" << B.getGrade() << "]" << std::endl;
	}
	else
		std::cout << "Form is already signed" << std::endl;
}

// Exceptions
const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}
const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}
