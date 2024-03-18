#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		_list.push_back(atoi(argv[i]));
		_vector.push_back(atoi(argv[i]));
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return (*this);
}
