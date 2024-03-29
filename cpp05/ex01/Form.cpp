#include "Form.hpp"

Form::Form(std::string name, int toSignGrade, int toExecGrade): _name(name), _toSignGrade(toSignGrade), _toExecGrade(toExecGrade){
	if (toSignGrade < 1 || toExecGrade < 1)
		throw GradeTooHighException(__FILE__, __LINE__);
	else if (toSignGrade > 150 || toExecGrade > 150)
		throw GradeTooLowException(__FILE__, __LINE__);
	_signed = false;
	std::cout << "Creating a new Form!!" << std::endl;
	return ;
}

Form::Form(const Form& form): _name(form._name), _toSignGrade(form._toSignGrade), _toExecGrade(form._toExecGrade){
	std::cout << "Copying a Form!!" << std::endl;
	*this = form;
	return ;
}

Form::~Form(){
	std::cout << "Erasing a Form!!" << std::endl;
	return ;
}

Form& Form::operator = (const Form& form){
	std::cout << "Copy & assign a Form!!" << std::endl;
	_signed = form._signed;
	return *this;
}

std::string	Form::getName(void) const{
	return _name;
}

int			Form::getSignGrade(void) const{
	return _toSignGrade;
}

int			Form::getExecGrade(void) const{
	return _toExecGrade;
}

bool		Form::getSignState(void) const{
	return _signed;
}

void		Form::beSigned(Bureaucrat& bure){
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

std::ostream&	operator << (std::ostream& out, const Form &form){
	out << form.getName() << ", with status ";
	if (form.getSignState() == true)
		out << "signed ";
	else
		out << "not signed ";
	out << "with required grade to sign " << form.getSignGrade()
	<< " and to execute " << form.getExecGrade();
	return out;
}
