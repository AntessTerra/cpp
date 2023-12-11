#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>

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

	class GradeTooHighException : public std::exception{
		virtual const char* what() const throw(){
			return "BUREAUCRAT EXCEPTION: GRADE TOO HIGH!!";
		}
	};

	class GradeTooLowException : public std::exception{
		virtual const char* what() const throw(){
			return "BUREAUCRAT EXCEPTION: GRADE TOO LOW!!";
		}
	};
};

std::ostream&	operator << (std::ostream& out, const Bureaucrat &bure);

#endif
