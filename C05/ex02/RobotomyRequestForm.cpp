#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy.getName(), copy.getSign_grade(), copy.getExecution_grade())
{
	setTarget(copy.getTarget());
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	setTarget(assign.getTarget());
	return *this;
}

bool	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == true)
	{
		if (executor.getGrade() <= getExecution_grade())
		{
			std::cout << "** Drilling noises ** ";
			if (rand() % 2 == 1)
				std::cout << getTarget() << " has been robotomized successfully" << std::endl;
			else
				std::cout << "robotomization failed" << std::endl;
			return true;
		}
		throw Form::GradeTooLowException();
	}
	std::cout << "Form unsigned!" << std::endl;
	return false;
}