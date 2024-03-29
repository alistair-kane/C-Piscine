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
#include <climits>
#include <cstdlib>

class    PmergeMe {

	public:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe(char *argv[]);
		~PmergeMe();

		PmergeMe & operator=(PmergeMe const & rhs);

		void	printTimestamp(std::string container, unsigned long value);
		void	printData(unsigned long value);
		void	do_sorts(void);

//list functions
		void	sort_list(int start_idx, int end_idx);
		void	merge_list(int start_idx, int mid_idx, int end_idx);
		void	insert_list(int start_idx, int mid_idx);
		int 	getValueAtIndex(std::list<int> input, int index);
		void	print_list(void);
		
//deque functions
		void	sort_deque(int start_idx, int end_idx);
		void	merge_deque(int start_idx, int mid_idx, int end_idx);
		void	insert_deque(int start_idx, int mid_idx);

	private:
		std::deque<int>	_deque;
		std::list<int>	_list;
		unsigned long	_begin_time;
		int				_K;
};

#endif
