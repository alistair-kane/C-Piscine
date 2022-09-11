#include <iostream>
#include "Array.hpp"
#include "Fixed.hpp"

#define MAX_VAL 750


int main(int, char**)
{
	// creates new array of size max val
	Array<int> numbers(MAX_VAL);
	Array<Fixed> fixed_numbers(MAX_VAL);
	// allocates space in memory for a pointer to an array of ints of size max val
	int* mirror = new int[MAX_VAL];
	Fixed *fixed_mirror = new Fixed[MAX_VAL];
	// puts a rand val in both places
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		fixed_numbers[i] = value;
		fixed_mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value in int array!!" << std::endl;
			return 1;
		}
		if (fixed_mirror[i] != fixed_numbers[i])
		{
			std::cerr << "didn't save the same value in Fixed array!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		fixed_numbers[-2] = Fixed(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		fixed_numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	delete [] fixed_mirror;
	return 0;
}