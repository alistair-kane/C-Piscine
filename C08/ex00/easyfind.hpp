#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
typename T::const_iterator easyfind(T & container, int an_integer)
{
	typename T::const_iterator pos;
	typename T::const_iterator end(container.end());
	for (pos = container.begin(); pos != end; ++pos)
	{
		if (*pos == an_integer)
			return (pos);
	}
	throw std::out_of_range("Container: Value not found!");
}

#endif
