#ifndef __PMERGEME__
#define __PMERGEME__

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>


class PmergeMe
{
private:
	std::list<int>		_list;
	std::vector<int>	_vector;
public:
	PmergeMe(int argc, char** argv);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);

	std::list<int> &getList() { return _list; }
	std::vector<int> &getVector() { return _vector; }
};

template <typename T>
void print(T& li){
	for (typename T::const_iterator it = li.begin(); it != li.end(); it++)
		std::cout << *it << std::endl;
}

#endif
