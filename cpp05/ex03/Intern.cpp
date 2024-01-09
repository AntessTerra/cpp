#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Creating a new Intern!!" << std::endl;
	return ;
}

AForm*	Intern::makePP(std::string target){
	return new PPForm(target);
}

AForm*	Intern::makeRR(std::string target){
	return new RRForm(target);
}

AForm*	Intern::makeSC(std::string target){
	return new SCForm(target);
}

Intern::Intern(const Intern& form){
	std::cout << "Copying a Intern!!" << std::endl;
	*this = form;
	return ;
}

Intern::~Intern(){
	std::cout << "Firing a Intern!!" << std::endl;
	return ;
}

Intern& Intern::operator = (const Intern& intern){
	(void) intern;
	return *this;
}

int	Intern::getFormNum(std::string name){
	std::string names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
		if (!name.compare(names[i]))
			return (i);
	return (-1);
}

AForm*	Intern::makeForm(std::string name, std::string target){
	int	num = getFormNum(name);
	if (num == -1)
		throw FormNotFoundException(__FILE__, __LINE__);
	function_p	forms[3] = {&Intern::makePP, &Intern::makeRR, &Intern::makeSC};
	std::cout << "Intern creates " << name << " form to target " << target << std::endl;
	return (this->*(forms[num]))(target);
}
