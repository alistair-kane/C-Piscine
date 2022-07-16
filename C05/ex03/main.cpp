/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:58:50 by alkane            #+#    #+#             */
/*   Updated: 2022/07/17 01:05:39 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Intern		Daniel;
	Form*		SCF;
	Bureaucrat	Saskia("Saskia", 100);
	Bureaucrat	Alistair("Alistair", 3);

	SCF = Daniel.makeForm("bushes creation", "garden");
	SCF = Daniel.makeForm("shrubbery creation", "garden");
	Saskia.executeForm(*SCF);
	Alistair.executeForm(*SCF);
	Alistair.signForm(*SCF);
	Alistair.executeForm(*SCF);

	delete SCF;
	return (0);
}