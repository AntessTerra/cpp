// #include "AForm.hpp"
#include "Intern.hpp"

int main(void){
	std::cout << "\nCreating\n" << std::endl;
	Intern someRando;

	AForm *pp, *rr, *sc , *test;

	pp = someRando.makeForm("presidential pardon", "Me");
	rr = someRando.makeForm("robotomy request", "Alan");
	sc = someRando.makeForm("shrubbery creation", "home");

	std::cout << *pp << std::endl;
	std::cout << *rr << std::endl;
	std::cout << *sc << std::endl;
	Bureaucrat admin("Admin", 1);
	// admin.signForm(pp);

	std::cout << "\nFail to create\n" << std::endl;

	try {
		test = someRando.makeForm("NOT EXISTS", "WRONG");
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nSingning\n" << std::endl;

	pp->beSigned(admin);
	admin.signForm(*rr);
	admin.signForm(*sc);
	std::cout << *pp << std::endl;

	std::cout << "\nTesting the execution\n" << std::endl;

	admin.executeForm(*pp);
	rr->execute(admin);

	try {
		sc->execute(admin);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nFailing the execution\n" << std::endl;

	try {
		Bureaucrat newGuy("NewGuy", 50);
		std::cout << newGuy << std::endl;

		newGuy.executeForm(*pp);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nFailing the execution for different reason\n" << std::endl;

	try {
		test = someRando.makeForm("presidential pardon", "test");

		admin.executeForm(*test);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		delete test;
	}

	std::cout << "\nErasing\n" << std::endl;
	delete pp;
	delete rr;
	delete sc;
}
