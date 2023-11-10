#include <iostream>

int main(void)
{
	std::string		hello = "HI THIS IS BRAIN";
	std::string*	stringPTR = &hello;
	std::string&	stringREF = hello;

	std::cout << &hello << " | " <<
	&stringPTR << " | " <<
	&stringREF << std::endl;

	std::cout << hello << " | " <<
	stringPTR << " | " <<
	stringREF << std::endl;
}
