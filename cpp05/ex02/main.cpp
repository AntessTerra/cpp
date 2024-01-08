// #include "AForm.hpp"
#include "PPForm.hpp"
#include "RRForm.hpp"
#include "SCForm.hpp"

int main(void){
	std::cout << "\nCreating\n" << std::endl;

	PPForm pp("Me");
	RRForm rr("Alan");
	SCForm sc("home");
	std::cout << pp << std::endl;
	std::cout << rr << std::endl;
	std::cout << sc << std::endl;
	Bureaucrat admin("Admin", 1);
	// admin.signForm(pp);
	pp.beSigned(admin);
	admin.signForm(rr);
	admin.signForm(sc);
	std::cout << pp << std::endl;

	std::cout << "\nCopying\n" << std::endl;

	PPForm copy(pp);
	std::cout << copy << std::endl;

	std::cout << "\nTesting the execution\n" << std::endl;

	admin.executeForm(pp);
	rr.execute(admin);

	try {
		sc.execute(admin);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nFailing the execution\n" << std::endl;

	try {
		Bureaucrat intern("Intern", 50);
		std::cout << intern << std::endl;

		intern.executeForm(pp);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nFailing the execution for different reason\n" << std::endl;

	try {
		PPForm test("test");

		admin.executeForm(test);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nErasing\n" << std::endl;
}
