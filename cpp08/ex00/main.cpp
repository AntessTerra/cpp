#include "easyfind.hpp"

int main(void){
	std::list<int> li;
	for (int count=0; count < 6; ++count)
		li.push_back(count);

	::print(li);

	try{std::cout << "\n\e[32mFOUND: " << ::easyfind(li, 3) << "\e[0m\n" << std::endl;}
	catch (std::exception& e){std::cerr << "\e[31mValue was not found!!\e[0m\n" << std::endl;}

	std::list<std::string> cha;
	std::string ahoj("ahoj");
	for (char count='A'; count <= 'H'; ++count){
		cha.push_back(ahoj.append(1, count));
		ahoj.erase(ahoj.length()-1, 1);
	}

	::print(cha);

	try{std::cout << "\n\e[32mFOUND: " << ::easyfind(cha, "ahojB") << "\e[0m\n" << std::endl;}
	catch (std::exception& e){std::cerr << "\e[31mValue was not found!!\e[0m\n" << std::endl;}
}
