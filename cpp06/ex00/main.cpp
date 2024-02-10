#include "ScalarConverter.hpp"

int main(int argc, char* argv[]){
	if (argc == 2)
		return ScalarConverter::convert(argv[1]);
	else
		return std::cout << "\e[31mINVALID NUMBER OF ARGUMENTS\e[0m" << std::endl, 1;
}
