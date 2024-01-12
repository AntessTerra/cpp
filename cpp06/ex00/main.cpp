#include "ScalarConverter.hpp"

int main(int argc, char* argv[]){
	if (argc == 2)
	{
		ScalarConverter s;
		(void) s;
		ScalarConverter::convert(argv[1]);

	}
	return 1;
}
