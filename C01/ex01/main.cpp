/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:03:32 by alistair          #+#    #+#             */
/*   Updated: 2022/06/24 01:52:39 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int		N = 10;
	Zombie *Hoard = zombieHoard(N, "Joes");
	
	for(int i = 0; i < N; i++)
	{
		std::cout << "[" << i << "] ";
		Hoard[i].announce();		
	}
	delete[] Hoard;
	return (0);
}