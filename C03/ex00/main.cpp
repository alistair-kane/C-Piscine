/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:53 by alkane            #+#    #+#             */
/*   Updated: 2022/07/27 14:58:24 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap john("John");
	ClapTrap jimmy("Jimmy");
	
	john.attack("Jimmy");
	jimmy.takeDamage(10);
	
	jimmy.attack("John");
	john.takeDamage(9);
	
	jimmy.beRepaired(10);
	john.beRepaired(10);
	
	jimmy.attack("John");

	std::cout << "Energy left for " << john.get_Name() << " : " << john.get_energy_points() << std::endl;
	std::cout << "Energy left for " << jimmy.get_Name() << " : " << jimmy.get_energy_points() << std::endl;
	
	std::cout << "HP left for " << john.get_Name() << " : " << john.get_hit_points() << std::endl;
	std::cout << "HP left for " << jimmy.get_Name() << " : " << jimmy.get_hit_points() << std::endl;
	return (0);
}