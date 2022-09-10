#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array(unsigned int size);
		Array(Array const &copy);

		Array & operator=(Array<T> const & assign);
		T & operator[](unsigned int index);

		unsigned int 	size();

		~Array();

	private:
		T				*_array;
		unsigned int	_size;
};

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	_array = new T[size];
	_size = size;
	for (unsigned int i = 0; i < size; i++)
		_array[i] = 0;
}

template <typename T>
Array<T>::Array(Array<T> const &copy)
{
	this->_size = copy._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const &assign)
{
	if (this == &assign)
		return (*this);
	if (this->_size > 0)
		delete [] this->_array;
	this->_size = assign._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = assign._array[i];
	return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Array: Index out of bounds!");
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return (this->_size);
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_size > 0)
		delete [] this->_array;
}

#endif


