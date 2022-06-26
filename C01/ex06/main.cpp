/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:47:47 by alistair          #+#    #+#             */
/*   Updated: 2022/06/26 02:39:33 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	find_pos(std::string level)
{
	std::string inputs[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == inputs[i])
			return (i);
	}
	return (4);
}

int main(int argc, char *argv[])
{
	Harl		harl;
	
	if (argc == 2)
	{
		switch (find_pos(argv[1]))
		{
			case DEBUG:
				std::cout << "[ DEBUG ]" << std::endl;
				harl.complain("DEBUG");
				std::cout << std::endl;
			case INFO:
				std::cout << "[ INFO ]" << std::endl;
				harl.complain("INFO");
				std::cout << std::endl;
			case WARNING:
				std::cout << "[ WARNING ]" << std::endl;
				harl.complain("WARNING");
				std::cout << std::endl;
			case ERROR:
				std::cout << "[ ERROR ]" << std::endl;
				harl.complain("ERROR");
				std::cout << std::endl;
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	return (0);
}