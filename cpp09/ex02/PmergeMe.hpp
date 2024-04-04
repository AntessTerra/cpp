#ifndef __PMERGEME__
#define __PMERGEME__

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>

bool isNumber(const std::string &s);

#define K 5

class PmergeMe
{
private:
	std::list<int>		_list;
	std::vector<int>	_vector;
	clock_t				_start, _end;
public:
	PmergeMe(int argc, char** argv);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);

	void mergeInsertSortList(std::list<int> &li);
	void mergeInsertSortVector(std::vector<int> &li);

	void insertionSortList(std::list<int> &li);
	void insertionSortVector(std::vector<int> &li);
};

template <typename T>
void print(T& li){
	typename T::const_iterator it = li.begin();
	if (li.size() < 10) {
		for (; it != li.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else {
		for (int i = 0; i++ < 10; it++)
			std::cout << *it << " ";
		std::cout << "..." << std::endl;
	}
}

template <typename T>
void merge(T &result, T &left, T &right) {
	result.clear();
	typename T::iterator it = left.begin(), it2 = right.begin();
	while (it != left.end() && it2 != right.end()) {
		if (*it < *it2)
			result.push_back(*it++);
		else
			result.push_back(*it2++);
	}
	result.insert(result.end(), it, left.end());
	result.insert(result.end(), it2, right.end());
}

// template <typename T>
// void insertionSort(T &li) {
// 	for (typename T::iterator it = li.begin(), next = it, insertion_point; it != li.end(); it++) {
// 		insertion_point = std::upper_bound(li.begin(), it, *it);
// 		std::advance(next, 1);
// 		std::rotate(insertion_point, it, next);
// 	}
// }

// template <typename T>
// void mergeInsertSort(T &li) {
// 	if (li.size() <= 1)
// 		return;
// 	if (li.size() <= K) {
// 		insertionSort(li);
// 		return;
// 	}
// 	else {
// 		T left, right;
// 		typename T::iterator mid = li.begin();
// 		std::advance(mid, li.size() / 2);
// 		left.assign(li.begin(), mid);
// 		right.assign(mid, li.end());
// 		mergeInsertSort(left);
// 		mergeInsertSort(right);
// 		merge(li, left, right);
// 	}
// }

template <typename T>
void allocate(T &li, int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		if (atoi(argv[i]) < 0 || !isNumber(argv[i]))
			throw std::invalid_argument("Invalid argument");
		if (std::find(li.begin(), li.end(), atoi(argv[i])) == li.end())
			li.push_back(atoi(argv[i]));
	}
}



#endif
