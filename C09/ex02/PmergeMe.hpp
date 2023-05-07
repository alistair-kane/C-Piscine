/*
	use positive integer sequence as argument
	./PmergeMe 3 5 9 7 4
	- start the timer for input checking
	- input checking
		- check number of args if it's at least 3 (main)
		- convert to numbers and check if they're bigger than 0 and smaller than MAXINT (checkInts())
		- adding numbers to containers
	- print out container before sorting
	- perform algorithm for both contaners
	- print out container after sorting
	- print out timer messages

*/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <stdexcept>
#include <fstream>

#include <sys/time.h>


class    PmergeMe {

	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe(char *argv[]);
		~PmergeMe();

		PmergeMe & operator=(PmergeMe const & rhs);

		bool	checkInts(char **input);

	private:
		// uint64_t		input_time;
		std::deque<int> _deque;
		std::list<int>  _list;
};

#endif