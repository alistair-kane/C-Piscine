#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, unsigned int sign_grade, unsigned int execution_grade);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		// Getters / Setters
		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int		getSign_grade() const;
		unsigned int		getExecution_grade() const;
		
		// Member Functions
		void				beSigned(Bureaucrat &B);

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
		bool 				_signed;
		unsigned int		_sign_grade;
		unsigned int		_execution_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Form &F);

#endif