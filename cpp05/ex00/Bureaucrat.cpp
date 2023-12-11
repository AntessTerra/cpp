#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Creating a new Bureacrat!!" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bure){
	std::cout << "Copying a Bureacrat!!" << std::endl;
	*this = bure;
	return ;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Firing a Bureacrat!!" << std::endl;
	return ;
}

Bureaucrat&		Bureaucrat::operator = (const Bureaucrat& bure){
	std::cout << "Copy & assign a Bureacrat!!" << std::endl;
	_grade = bure.getGrade();
	return *this;
}

std::ostream&	operator << (std::ostream& out, const Bureaucrat &bure){
	out << bure.getName() << ", bureaucrat grade " << bure.getGrade() << ".";
	return out;
}

std::string	Bureaucrat::getName(void) const{
	return _name;
}

int			Bureaucrat::getGrade(void) const{
	return _grade;
}

void		Bureaucrat::deGrade(int howMuch){
	if ((_grade + howMuch) < 1)
		throw GradeTooHighException();
	else if ((_grade + howMuch) > 150)
		throw GradeTooLowException();
	_grade += howMuch;
	std::cout << "Degraded a Bureacrat to " << _grade << " !!" << std::endl;
	return ;
}

void		Bureaucrat::gradeUp(int howMuch){
	if ((_grade - howMuch) < 1)
		throw GradeTooHighException();
	else if ((_grade - howMuch) > 150)
		throw GradeTooLowException();
	_grade -= howMuch;
	std::cout << "A Bureacrat gradedUP to " << _grade << " !!" << std::endl;
	return ;
}
