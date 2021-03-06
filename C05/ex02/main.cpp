/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:58:50 by alkane            #+#    #+#             */
/*   Updated: 2022/07/16 23:54:05 by alistair         ###   ########.fr       */
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
	
	PresidentialPardonForm PPF("Joe");
	Daniel.signForm(PPF);
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