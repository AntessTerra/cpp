#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2)
		return std::cout << "Error: wrong number of arguments.\nUsage ./RPN <Polish mathematical expression>" << std::endl, 1;
	else {
		try { RPN rpn(argv[1]); }
		catch (std::invalid_argument &e) {
			std::cout << "Error: " << e.what() << std::endl;}
	}
	return 0;
}
