#include "RRForm.hpp"

RRForm::RRForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << "Creating a new RRForm!!" << std::endl;
	return ;
}

RRForm::RRForm(const RRForm& form): AForm("RobotomyRequestForm", 72, 45){
	std::cout << "Copying a RRForm!!" << std::endl;
	*this = form;
	return ;
}

RRForm::~RRForm(){
	std::cout << "Erasing a RRForm!!" << std::endl;
	return ;
}

RRForm& RRForm::operator = (const RRForm& form){
	std::cout << "Copy & assign a RRForm!!" << std::endl;
	if (form.getSignState()){
		Bureaucrat tmp("tmp", form.getSignGrade());
		this->beSigned(tmp);
	}
	return *this;
}

void		RRForm::printExecMessage() const{
	srand((int)time(0));
	std::cout << "🦾 DRILLING NOICES 🦿" << std::endl;
	if ((rand() % 100) > 50)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy has failed." << std::endl;
	return ;
}
