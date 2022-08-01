/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:58:50 by alkane            #+#    #+#             */
/*   Updated: 2022/08/01 14:16:42 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	Daniel("Daniel", 1);
	Bureaucrat	Peasant("Pleb", 140);

	PresidentialPardonForm PPF("Joe");
	// test << operator overload
	std::cout << PPF << std::endl;

	Peasant.signForm(PPF);
	Daniel.signForm(PPF);
	
	// test exception where form is signed but execution grade is too low
	try
	{
		Peasant.executeForm(PPF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Daniel.executeForm(PPF);

	ShrubberyCreationForm SCF("garden");
	Daniel.executeForm(SCF);
	Daniel.signForm(SCF);
	Daniel.executeForm(SCF);

	RobotomyRequestForm RCF("Subject");
	Daniel.signForm(RCF);
	Daniel.executeForm(RCF);

	return (0);
}