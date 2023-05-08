/*
	verify the input argv that it contains only numerical 0 - 9
		and tokens + - / *
*/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>

#include <sys/time.h>


class    RPN {

	public:
		RPN();
		RPN(RPN const & src);
		RPN(char *argv[]);
		~RPN();

		RPN & operator=(RPN const & rhs);

	private:
		std::vector<std::string>	_data;
		static const std::string	_allowed[5];
};

#endif