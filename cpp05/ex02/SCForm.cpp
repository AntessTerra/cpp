#include "SCForm.hpp"

SCForm::SCForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "Creating a new SCForm!!" << std::endl;
	return ;
}

SCForm::SCForm(const SCForm& form): AForm("ShrubberyCreationForm", 145, 137){
	std::cout << "Copying a SCForm!!" << std::endl;
	*this = form;
	return ;
}

SCForm::~SCForm(){
	std::cout << "Erasing a SCForm!!" << std::endl;
	return ;
}

SCForm& SCForm::operator = (const SCForm& form){
	std::cout << "Copy & assign a SCForm!!" << std::endl;
	if (form.getSignState()){
		Bureaucrat tmp("tmp", form.getSignGrade());
		this->beSigned(tmp);
	}
	return *this;
}

void		SCForm::printExecMessage() const{
	std::cout << "🌳 GROWING ASCII TREE 🌳" << std::endl;
	if (_target.length() > 0){
		if (_target == "home"){
			system("tree ~ > home_shrubbery");
			std::cout << "📂 Result saved to home_shrubbery file 📂" << std::endl;
		}
		else {
			std::string path("tree " + _target + " > " + _target + "_shrubbery");
			struct stat sb;
			if (stat(_target.c_str(), &sb) == 0){
				system(path.c_str());
				std::cout << "📂 Result saved to " << _target << "_shrubbery file 📂" << std::endl;
			}
			else {
				std::cout << "❗ Result unsaved ❗" << std::endl;
				throw FileNotFoundException(__FILE__, __LINE__);
			}
		}
	}
	else {
		system("tree . > ._shrubbery");
		std::cout << "📂 Result saved to ._shrubbery file 📂" << std::endl;
	}
	return ;
}
