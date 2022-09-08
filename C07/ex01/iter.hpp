#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void	iter(T *array, size_t len, void (*func)(T &element))
{
	for (size_t i = 0; i < len; i++)
	{
		(*func)(array[i]);
	}
}

template <typename T>
void	print_element(T &element)
{
	std::cout << element << std::endl;
}

#endif
