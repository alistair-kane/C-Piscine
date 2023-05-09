/*
	verify the input argv that it contains only numerical 0 - 9
		and tokens + - / *
*/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <algorithm>

#include <sys/time.h>


class    RPN {

	public:
		RPN();
		RPN(RPN const & src);
		RPN(int argc, char *argv[]);
		~RPN();

		RPN & operator=(RPN const & rhs);

	private:
		int		_top_pop();
		bool	_calculate(char *argv[]);

		std::stack<int>				_data;
};

#endif