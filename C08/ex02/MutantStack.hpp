#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(MutantStack const & copy) { *this = copy; };

		MutantStack & operator=(MutantStack const & assign)
		{
			std::stack<T>::operator=(assign);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	rev_iterator;

		iterator		begin(void) { return (std::stack<T>::c.begin()); }
		iterator		end(void) { return (std::stack<T>::c.end()); }

		rev_iterator	rbegin(void) { return (std::stack<T>::c.rbegin()); }
		rev_iterator	rend(void) { return (std::stack<T>::c.rend()); }

		virtual ~MutantStack(void) {};

	private:

};

#endif
