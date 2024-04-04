#include "PmergeMe.hpp"

bool isNumber(const std::string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		if (!isdigit(s[i]))
			return false;
	}
	return true;
}

void PmergeMe::insertionSortList(std::list<int> &li){
	for (std::list<int>::iterator it = li.begin(); it != li.end(); it++) {
		std::list<int>::iterator insertion_point = std::upper_bound(li.begin(), it, *it), next = it;
		std::advance(next, 1);
		std::rotate(insertion_point, it, next);
	}
}

void PmergeMe::mergeInsertSortList(std::list<int> &li){
	if (li.size() <= 1)
		return;
	if (li.size() <= K) {
		insertionSortList(li);
		return;
	}
	else {
		std::list<int> left, right;
		std::list<int>::iterator mid = li.begin();
		std::advance(mid, li.size() / 2);
		left.assign(li.begin(), mid);
		right.assign(mid, li.end());
		// std::cout << "left.size() = " << left.size() << std::endl;
		// print(left);
		// std::cout << "right.size() = " << right.size() << std::endl;
		// print(right);
		mergeInsertSortList(left);
		mergeInsertSortList(right);
		merge(li, left, right);
	}
}

void PmergeMe::insertionSortVector(std::vector<int> &ve){
	for (std::vector<int>::iterator it = ve.begin(), insertion_point; it != ve.end(); it++) {
		insertion_point = std::upper_bound(ve.begin(), it, *it);
		std::rotate(insertion_point, it, it + 1);
	}
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &ve){
	if (ve.size() <= 1)
		return;
	if (ve.size() <= K) {
		insertionSortVector(ve);
		return;
	}
	else {
		std::vector<int> left, right;
		std::vector<int>::iterator mid = ve.begin() + ve.size() / 2;
		left.assign(ve.begin(), mid);
		right.assign(mid, ve.end());
		mergeInsertSortVector(left);
		mergeInsertSortVector(right);
		merge(ve, left, right);
	}
}

PmergeMe::PmergeMe(int argc, char** argv){
	std::vector<int>	tmp;
	allocate(tmp, argc, argv);

	std::cout << "Before: ";
	print(tmp);

	_start = clock();
	allocate(_list, argc, argv);
	mergeInsertSortList(_list);
	_end = clock();
	double elapsed = double(_end - _start) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	print(_list);
	std::cout << "\e[33mTime to process a range of " << argc - 1 << " elements with std::list : " << std::fixed << std::setprecision(6) << elapsed  << " seconds\e[0m" << std::endl;

	_start = clock();
	allocate(_vector, argc, argv);
	mergeInsertSortVector(_vector);
	_end = clock();
	elapsed = double(_end - _start) / CLOCKS_PER_SEC;
	std::cout << "\e[35mTime to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(6) << elapsed  << " seconds\e[0m" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return (*this);
}
