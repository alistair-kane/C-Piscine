/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:28:46 by alkane            #+#    #+#             */
/*   Updated: 2022/07/15 16:18:14 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl << "------------------------" << std::endl << std::endl;

	int N = 4;
	Animal* animals[N];

	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < N; i++)
		std::cout << animals[i]->getType() << " " << std::endl;
	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << std::endl << "------------------------" << std::endl << std::endl;

	Dog old_test_dog;
	Dog new_test_dog;

	old_test_dog.setIdeas(0, "I want food");
	new_test_dog = old_test_dog;
	old_test_dog.setIdeas(0, "Im not hungry");
	
	std::cout << "Idea at index 0: " << old_test_dog.getIdeas(0) << std::endl;
	std::cout << "Idea at index 0: " << new_test_dog.getIdeas(0) << std::endl;


	return (0);
}