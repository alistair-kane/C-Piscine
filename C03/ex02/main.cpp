/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:53 by alkane            #+#    #+#             */
/*   Updated: 2022/07/02 23:38:13 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap john("John");
    FragTrap jimmy("Jimmy");
    
    john.attack("Jimmy"); 
    jimmy.takeDamage(9);
    
    jimmy.attack("john");
    john.takeDamage(9);
    
    jimmy.beRepaired(10);
    john.beRepaired(10);
    
    std::cout << "Energy left for " << john.get_Name() << " : " << john.get_energy_points() << std::endl;
    std::cout << "Energy left for " << jimmy.get_Name() << " : " << jimmy.get_energy_points() << std::endl;
    
    std::cout << "HP left for " << john.get_Name() << " : " << john.get_hit_points() << std::endl;
    std::cout << "HP left for " << jimmy.get_Name() << " : " << jimmy.get_hit_points() << std::endl;
    
    jimmy.highFivesGuys();
    john.highFivesGuys();
    
    return (0);
}