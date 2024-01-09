#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <sstream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bure);
	~Bureaucrat();
	Bureaucrat& operator = (const Bureaucrat& bure);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		deGrade(int howMuch);
	void		gradeUp(int howMuch);
	void		signForm(Form& form);

	class GradeTooHighException{
	public:
		GradeTooHighException(std::string file, int line) {
			std::stringstream ss;
			ss << "\e[30m" << file << ":" << line << std::endl << "\e[31mBUREAUCRAT EXCEPTION: GRADE TOO HIGH!!\e[0m";
			throw std::runtime_error(ss.str().c_str());
		}
	};

	class GradeTooLowException{
	public:
		GradeTooLowException(std::string file, int line) {
			std::stringstream ss;
			ss << "\e[30m" << file << ":" << line << std::endl << "\e[31mBUREAUCRAT EXCEPTION: GRADE TOO LOW!!\e[0m";
			throw std::runtime_error(ss.str().c_str());
		}
	};
};

std::ostream&	operator << (std::ostream& out, const Bureaucrat &bure);

#endif
