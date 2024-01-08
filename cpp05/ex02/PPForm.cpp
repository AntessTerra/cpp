#include "PPForm.hpp"

PPForm::PPForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "Creating a new PPForm!!" << std::endl;
	return ;
}

PPForm::PPForm(const PPForm& form): AForm("PresidentialPardonForm", 25, 5){
	std::cout << "Copying a PPForm!!" << std::endl;
	*this = form;
	return ;
}

PPForm::~PPForm(){
	std::cout << "Erasing a PPForm!!" << std::endl;
	return ;
}

PPForm& PPForm::operator = (const PPForm& form){
	std::cout << "Copy & assign a PPForm!!" << std::endl;
	if (form.getSignState()){
		Bureaucrat tmp("tmp", form.getSignGrade());
		this->beSigned(tmp);
	}
	return *this;
}
