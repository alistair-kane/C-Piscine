#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string name, unsigned int grade);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);
		
		// Getters / Setters
		const std::string	getName() const;
		unsigned int 		getGrade() const;
		
		// Member Functions
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &F);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		const std::string	_name;
		unsigned int		_grade;
		
};

std::ostream	& operator<<(std::ostream &os, const Bureaucrat &B);

#endif