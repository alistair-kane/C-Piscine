#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <ctime>
# include <cstdlib>

class Span
{
	public:
		Span(void);
		Span(Span const & copy);

		Span(unsigned int n);

		Span & operator=(const Span &assign);

		void			addNumber(int n);
		void			randomFill(void);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		~Span(void);
	private:
		static int			randomNumberGen(void);
		unsigned int		_n;
		std::vector<int>	*_storage;
};

#endif
