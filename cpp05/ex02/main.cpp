// #include "AForm.hpp"
#include "PPForm.hpp"

int main(void){
	PPForm pp("Me");
	std::cout << pp << std::endl;
	Bureaucrat admin("Admin", 1);
	pp.beSigned(admin);
	std::cout << pp << std::endl;
	PPForm copy(pp);
	std::cout << copy << std::endl;
}
