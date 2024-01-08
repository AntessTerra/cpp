#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <sstream>
#include "AForm.hpp"

class AForm;

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
	void		signForm(AForm& aform);
	void		executeForm(AForm const & aform) const;

	class GradeTooHighException{
	public:
		GradeTooHighException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "BUREAUCRAT EXCEPTION: GRADE TOO HIGH!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};

	class GradeTooLowException{
	public:
		GradeTooLowException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "BUREAUCRAT EXCEPTION: GRADE TOO LOW!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};
};

std::ostream&	operator << (std::ostream& out, const Bureaucrat &bure);

#endif
