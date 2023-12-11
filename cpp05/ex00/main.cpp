#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat bur = Bureaucrat("ME", 1);
	try {
		std::cout << "\nTHROWING AN EXCEPTION\n" << std::endl;
		Bureaucrat wrong = Bureaucrat("Peter", 151);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\nCOPYING SOME STUFF\n" << std::endl;
		Bureaucrat copy(bur);
		Bureaucrat copy2 = bur;

		std::cout << bur << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\nMODIFING GRADES\n" << std::endl;
		bur.deGrade(50);
		std::cout << bur << std::endl;
		bur.gradeUp(51);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
