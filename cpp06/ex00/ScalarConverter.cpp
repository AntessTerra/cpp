#include "ScalarConverter.hpp"

int ScalarConverter::getType(std::string str){
	if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
		return FLOAT;
	if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
		return DOUBLE;
	if (str.length() == 1 && std::isprint(str[0]) && (str[0] < '0' || str[0] > '9'))
		return CHAR;
	if (str.find_first_not_of("-0123456789.f") != str.npos)
		return INVALID;
	std::string::size_type dot = str.find_first_of("."), f = str.find_first_of("f");
	if (dot != str.npos){
		if (str.find_last_of(".") != dot || dot == str.length() - 1 || dot == 0)
			return INVALID;
		if (f != str.npos && f == str.length() - 1){
			if (str.find_last_of("f") != f || !std::isalnum(str[f - 1]))
				return INVALID;
			return FLOAT;
		}
		return DOUBLE;
	}
	else if (str.find_first_not_of("-0123456789") == str.npos)
		return INT;
	else
		return INVALID;
}
// \u221E == '∞'
int ScalarConverter::convert(std::string str){
	int type = getType(str);
	std::stringstream ss(str);
	std::cout << std::fixed << std::setprecision(1);
	switch (type){
		case CHAR:
		{
			std::cout << "\e[32mINPUT TYPE CHAR\e[0m" << std::endl << std::endl;
			std::cout << "char: '" << str[0] << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
			break;
		}
		case INT:
		{
			std::cout << "\e[33mINPUT TYPE INT\e[0m" << std::endl << std::endl;
			int input;
			ss >> input;
			if (input >= 0 && input <= 31)
				std::cout << "char: NON PRINTABLE" << std::endl;
			else if (input < 0 || input > 127)
				std::cout << "char: OUT OF ASCII BOUNDS" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
			std::cout << "int: " << input << std::endl;
			std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(input) << std::endl;
			break;
		}
		case FLOAT:
		{
			std::cout << "\e[34mINPUT TYPE FLOAT\e[0m" << std::endl << std::endl;
			float input;
			if (str == "inff" || str == "+inff")
				input = INFINITY;
			else if (str == "-inff")
				input = - INFINITY;
			else if (str == "nanf")
				input = NAN;
			else
				ss >> input;
			if (std::isinf(input) || std::isnan(input) || input < 0 || input > 127)
				std::cout << "char: OUT OF ASCII BOUNDS" << std::endl;
			else if (input >= 0 && input <= 31)
				std::cout << "char: NON PRINTABLE" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
			if (std::isinf(input) || std::isnan(input) || input < INT_MIN || input > INT_MAX)
				std::cout << "int: OUT OF INT BOUNDS" << std::endl;
			else
				std::cout << "int: " <<  static_cast<int>(input) << std::endl;
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(input) << std::endl;
			break;
		}
		case DOUBLE:
		{
			std::cout << "\e[35mINPUT TYPE DOUBLE\e[0m" << std::endl << std::endl;
			float input;
			if (str == "inf" || str == "+inf")
				input = INFINITY;
			else if (str == "-inf")
				input = - INFINITY;
			else if (str == "nan")
				input = NAN;
			else
				ss >> input;
			if (std::isinf(input) || std::isnan(input) || input < 0 || input > 127)
				std::cout << "char: OUT OF ASCII BOUNDS" << std::endl;
			else if (input >= 0 && input <= 31)
				std::cout << "char: NON PRINTABLE" << std::endl;
			else
				std::cout << "char: '" << static_cast<char>(input) << "'" << std::endl;
			if (std::isinf(input) || std::isnan(input) || input < INT_MIN || input > INT_MAX)
				std::cout << "int: OUT OF INT BOUNDS" << std::endl;
			else
				std::cout << "int: " <<  static_cast<int>(input) << std::endl;
			std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
			break;
		}
		default:
			std::cout << "\e[31mINVALID TYPE\e[0m" << std::endl;
			return 1;
	}
	return 0;
}
