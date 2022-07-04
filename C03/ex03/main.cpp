/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:25:53 by alkane            #+#    #+#             */
/*   Updated: 2022/07/04 20:24:51 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap monster("monster");
    
    monster.attack("Jimmy"); 

    // monster.beRepaired(10);
    
    std::cout << "Energy left for " << monster.get_Name() << " : " << monster.get_energy_points() << std::endl;
    
    std::cout << "HP left for " << monster.get_Name() << " : " << monster.get_hit_points() << std::endl;

    std::cout << "Attack damage " << monster.get_Name() << " : " << monster.get_attack_damage() << std::endl;
    
    monster.whoAmI();
    return (0);
}