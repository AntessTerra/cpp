#ifndef __FORM__
#define __FORM__

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_toSignGrade, _toExecGrade;
public:
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form& form);
	~Form();
	Form& operator = (const Form& form);

	std::string	getName(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	bool		getSignState(void) const;
	void		beSigned(Bureaucrat& bure);

	class GradeTooHighException{
	public:
		GradeTooHighException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "FORM EXCEPTION: GRADE TOO HIGH!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};

	class GradeTooLowException{
	public:
		GradeTooLowException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "FORM EXCEPTION: GRADE TOO LOW!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};

	class AlreadySignedException{
	public:
		AlreadySignedException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "FORM EXCEPTION: ALREADY SIGNED!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};
};

std::ostream&	operator << (std::ostream& out, const Form &form);

#endif
