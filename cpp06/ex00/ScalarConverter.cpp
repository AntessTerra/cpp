#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str){
	char c = str[0];
	int i = static_cast <int> (c);
	float f = static_cast <float> (c);
	double d = static_cast <double> (c);
	std::cout << "char: " << c << std::endl
	<< "int: " << i << std::endl
	<< "float: " << f << std::endl
	<< "double: " << d << std::endl;
	return ;
}
