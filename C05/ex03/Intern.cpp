#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

Form*	Intern::makePPF(std::string const target)
{
	return new PresidentialPardonForm(target);
}

Form*	Intern::makeRFP(std::string const target)
{
	return new RobotomyRequestForm(target);
}

Form*	Intern::makeSCF(std::string const target)
{
	return new ShrubberyCreationForm(target);
}

Form*	Intern::makeForm(std::string form_name, std::string target)
{
	makeFunc f[3] = {&Intern::makePPF, &Intern::makeRFP, &Intern::makeSCF};
	std::string f_names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	for(int i = 0; i < 3; i++)
	{
		if (form_name == f_names[i])
			return (this->*f[i])(target);
	}
	std::cout << "Input :[" << form_name << "] - No matching form found" << std::endl;
	std::cout << "Options: " << std::endl;
	for(int i = 0; i < 3; i++)
		std::cout << i << ".\t" << f_names[i] << std::endl;
	return (NULL);
}
