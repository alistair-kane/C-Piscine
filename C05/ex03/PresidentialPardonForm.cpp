#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
{
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy.getName(), copy.getSign_grade(), copy.getExecution_grade())
{
	setTarget(copy.getTarget());
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	setTarget(assign.getTarget());
	return *this;
}

bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == true)
	{
		if (executor.getGrade() <= getExecution_grade())
		{

			std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
			return true;
		}
		throw Form::GradeTooLowException();
	}
	std::cout << "Form unsigned!" << std::endl;
	return false;
}