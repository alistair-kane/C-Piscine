#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);
		
		// Member functions
		Form*	makeForm(std::string form_name, std::string target);
		typedef	Form* (Intern::*makeFunc)(const std::string);

	private:
		Form*	makePPF(std::string const target);
		Form*	makeRFP(std::string const target);
		Form*	makeSCF(std::string const target);
};

#endif