#include <iostream>
#include <list>

// *** COLORS ***//
# define BLANK "\e[0m"
# define BLA "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELL "\033[0;33m"
# define BLU "\033[0;34m"
# define PU "\033[0;35m"
# define CY "\033[0;36m"
# define WH "\033[0;37m"
# define D "\033[0m"

void	print_list(std::list<int> &myList) {

	std::list<int>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void    insert_list(int start_idx, int mid_idx, std::list<int> &_list)
{
	std::list<int>::iterator it = _list.begin();
	// increase iterator to correct position
	for (int i = 0; i < start_idx; i++)
		++it;
	// std::cout << YELL "the value of it: " D << *it << std::endl;
	
	std::list<int>::iterator start_it = it;
	// std::cout << CY "the value of start_it: " D << *it << std::endl;
	std::list<int>::iterator end_it = _list.begin();
	// increase iterator to correct position
	for (int i = 0; i < mid_idx; i++)
		++end_it;


	while (it != end_it) 
	{

		std::list<int>::iterator insertionPos = start_it;
		while (insertionPos != it && *insertionPos <= *it)
		{
			++insertionPos;
		}

		int tmp = *insertionPos;
		*insertionPos = *it;
		*it = tmp;
		
		it = insertionPos;
		it++;
		// _list.insert(insertionPos, *it);
		// it = _list.erase(it);
	}
	std::cout << PU;
	print_list(_list);
}

int main(void) {

	std::list<int> myList;

	myList.push_back(6); //0
	myList.push_back(7); //1
	myList.push_back(1); //2
	myList.push_back(9); //3
	myList.push_back(3); //4
	myList.push_back(8); //5
	myList.push_back(5); //6
	myList.push_back(4); //7
	myList.push_back(0); //8
	myList.push_back(2); //9

	std::cout << PU "Before sorting the first half of list" D << std::endl;
	print_list(myList);

	std::cout << GREEN "After sorting the first half of list" D << std::endl;
	insert_list(0, 5, myList);
	// print_list(myList);

	insert_list(5, 10, myList);
	std::cout << CY "After sorting the second half of list" D << std::endl;
	print_list(myList);

	return (0);
}