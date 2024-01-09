#include "AForm.hpp"

AForm::AForm(std::string name, int toSignGrade, int toExecGrade): _name(name), _toSignGrade(toSignGrade), _toExecGrade(toExecGrade){
	if (toSignGrade < 1 || toExecGrade < 1)
		throw GradeTooHighException(__FILE__, __LINE__);
	else if (toSignGrade > 150 || toExecGrade > 150)
		throw GradeTooLowException(__FILE__, __LINE__);
	_signed = false;
	std::cout << "Creating a new AForm!!" << std::endl;
	return ;
}

AForm::AForm(const AForm& form): _name(form._name), _toSignGrade(form._toSignGrade), _toExecGrade(form._toExecGrade){
	std::cout << "Copying a AForm!!" << std::endl;
	*this = form;
	return ;
}

AForm::~AForm(){
	std::cout << "Erasing a AForm!!" << std::endl;
	return ;
}

AForm& AForm::operator = (const AForm& form){
	std::cout << "Copy & assign a AForm!!" << std::endl;
	_signed = form._signed;
	return *this;
}

std::string	AForm::getName(void) const{
	return _name;
}

int			AForm::getSignGrade(void) const{
	return _toSignGrade;
}

int			AForm::getExecGrade(void) const{
	return _toExecGrade;
}

bool		AForm::getSignState(void) const{
	return _signed;
}

void		AForm::beSigned(Bureaucrat& bure){
	if (bure.getGrade() > _toSignGrade && _signed == false){
		std::cout << bure.getName() << " couldn't sign " << getName() << " because grade too low" << std::endl;
		throw GradeTooLowException(__FILE__, __LINE__);
	}
	else if (_signed == true)
		throw AlreadySignedException(__FILE__, __LINE__);
	_signed = true;
	std::cout << bure.getName() << " signed " << getName() << std::endl;
	return ;
}

void		AForm::printExecMessage() const{
	std::cout << "Abstract class text" << std::endl;
	return ;
}

void		AForm::execute(Bureaucrat const & executor) const{
	if (_signed == false)
		throw NotSignedException(__FILE__, __LINE__);
	else if (executor.getGrade() > _toExecGrade)
		throw GradeTooLowException(__FILE__, __LINE__);
	else {
		std::cout << std::endl << executor.getName() << " executed " << getName() << std::endl << std::endl;
		printExecMessage();
	}
	return ;
}

std::ostream&	operator << (std::ostream& out, const AForm &form){
	out << form.getName() << ", with status ";
	if (form.getSignState() == true)
		out << "🖋️  ";
	else
		out << "🗋  ";
	out << "required to ✍️  " << form.getSignGrade()
	<< " and to 🔨 " << form.getExecGrade();
	return out;
}
