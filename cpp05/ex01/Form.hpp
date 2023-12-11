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

	class GradeTooHighException : public std::exception{
		virtual const char* what() const throw(){
			return "FORM EXCEPTION: GRADE TOO HIGH!!";
		}
	};

	class GradeTooLowException : public std::exception{
		virtual const char* what() const throw(){
			return "FORM EXCEPTION: GRADE TOO LOW!!";
		}
	};

	class AlreadySignedException : public std::exception{
		virtual const char* what() const throw(){
			return "FORM EXCEPTION: ALREADY SIGNED!!";
		}
	};
};

std::ostream&	operator << (std::ostream& out, const Form &form);

#endif
