/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:29:48 by alkane            #+#    #+#             */
/*   Updated: 2022/07/14 15:04:04 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void)
{
	if (weapon != NULL)
		std::cout << name << " attacks with their weapon " << (*weapon).getType() << std::endl;
	else
		std::cout << name << " attacks with no weapon " << std::endl;
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	weapon = &_weapon;
}
