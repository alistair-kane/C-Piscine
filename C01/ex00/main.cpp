/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:03:32 by alistair          #+#    #+#             */
/*   Updated: 2022/06/23 23:59:50 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Joe = newZombie("Joe");

	Joe->announce();
	delete Joe;

	randomChump("Jimmy");
	return (0);
}