#include "Form.hpp"

int main(void){
	Form form = Form("GDPR", 10, 1);
	try {
		std::cout << "\nTHROWING AN EXCEPTION\n" << std::endl;
		Form wrong = Form("Wrong", 1, 151);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\nCOPY CAT\n" << std::endl;
		Form copy(form);
		Form copy2 = form;

		std::cout << copy << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\nGET SIGNED\n" << std::endl;
		Bureaucrat bure = Bureaucrat("ME", 1);
		form.beSigned(bure);

		std::cout << "\nOR NOT\n" << std::endl;
		bure.signForm(form);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "\nNOT GET SIGNED\n" << std::endl;
		Bureaucrat toolow = Bureaucrat("TooLow", 50);
		Form ownership = Form("OWNERSHIP", 10, 1);
		ownership.beSigned(toolow);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
