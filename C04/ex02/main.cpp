/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:28:46 by alkane            #+#    #+#             */
/*   Updated: 2022/07/15 16:54:43 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const A_Animal* j = new Dog();
	const A_Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl << "------------" << std::endl << std::endl;

	int N = 4;
	A_Animal* A_Animals[N];

	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			A_Animals[i] = new Dog();
		else
			A_Animals[i] = new Cat();
	}

	for (int i = 0; i < N; i++)
		std::cout << A_Animals[i]->getType() << " " << std::endl;
	for (int i = 0; i < N; i++)
		delete A_Animals[i];

	std::cout << std::endl << "------------" << std::endl << std::endl;

	Dog old_test_dog;
	Dog new_test_dog;

	old_test_dog.setIdeas(0, "I want food");
	new_test_dog = old_test_dog;
	old_test_dog.setIdeas(0, "Im not hungry");
	
	std::cout << "Idea at index 0: " << old_test_dog.getIdeas(0) << std::endl;
	std::cout << "Idea at index 0: " << new_test_dog.getIdeas(0) << std::endl;

	// Abstract class test
	// A_Animal Fred;

	return (0);
}