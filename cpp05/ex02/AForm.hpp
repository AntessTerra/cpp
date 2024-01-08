#ifndef __AFORM__
#define __AFORM__

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_toSignGrade, _toExecGrade;
public:
	AForm(std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm& aform);
	~AForm();
	AForm& operator = (const AForm& aform);

	std::string	getName(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	bool		getSignState(void) const;
	void		beSigned(Bureaucrat& bure);
	void		execute(Bureaucrat cosnt & executor) const;
	void		printExecMessage(Bureaucrat cosnt & executor) const = 0;

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

	class NotSignedException{
	public:
		NotSignedException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "FORM EXCEPTION: FORM NOT SIGNED YET!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};
};

std::ostream&	operator << (std::ostream& out, const AForm &form);

#endif
