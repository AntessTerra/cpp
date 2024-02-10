#include "TypeDetector.hpp"

Base::~Base(){}

Base**	generate(int N){
	Base** array = new Base*[N];

	srand(time(0));
	for (int i = 0; i < N; i++){
		switch (rand() % 3){
			case 0:
				std::cout << "\e[32mNew A has appeared\e[0m" << std::endl, array[i] = new A;
				break;
			case 1:
				std::cout << "\e[33mNew B has appeared\e[0m" << std::endl, array[i] = new B;
				break;
			case 2:
				std::cout << "\e[34mNew C has appeared\e[0m" << std::endl, array[i] = new C;
				break;
		}
	}
	return (array);
}

void	identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "\e[32mA has been identified from a pointer\e[0m" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "\e[33mB has been identified from a pointer\e[0m" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "\e[34mC has been identified from a pointer\e[0m" << std::endl;
}

void	identify(Base& p){
	try {
		dynamic_cast<A&>(p);
		std::cout << "\e[32mA has been identified from a reference\e[0m" << std::endl;
	} catch (const std::exception& e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "\e[33mB has been identified from a reference\e[0m" << std::endl;
	} catch (const std::exception& e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "\e[34mC has been identified from a reference\e[0m" << std::endl;
	} catch (const std::exception& e) {}
}
