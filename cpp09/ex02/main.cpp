#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc <= 1)
		return std::cout << "Error: wrong number of arguments.\nUsage ./PmergeMe <int> <int> ..." << std::endl, 1;
	else {
		try {
			PmergeMe pme(argc, argv);

			print(pme.getList());
			print(pme.getVector());
		}
		catch (std::invalid_argument &e) {
			std::cout << "Error: " << e.what() << std::endl;}
	}
	return 0;
}
