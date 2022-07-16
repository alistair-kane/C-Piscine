#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy.getName(), copy.getSign_grade(), copy.getExecution_grade())
{
	setTarget(copy.getTarget());
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	setTarget(assign.getTarget());
	return *this;
}

bool	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ifstream in_file("tree.txt");
	std::ofstream out_file;
	std::string line;

	if (getSigned() == true)
	{
		if (executor.getGrade() <= getExecution_grade())
		{
			out_file.open(getTarget() + "_shrubbery");
			if (!out_file)
				std::cout << "oops computer broken (file couldnt be created)" << std::endl;
			else
			{
				while (getline(in_file, line))
					out_file << line << "\n";
				in_file.close();
				out_file.close();
			}
			return true;
		}
		throw Form::GradeTooLowException();
	}
	std::cout << "Form unsigned!" << std::endl;
	return false;
}