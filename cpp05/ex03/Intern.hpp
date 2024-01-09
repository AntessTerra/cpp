#ifndef __INTERN__
#define __INTERN__

#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include "PPForm.hpp"
#include "RRForm.hpp"
#include "SCForm.hpp"

class Intern
{
private:
	AForm*	makePP(std::string target);
	AForm*	makeRR(std::string target);
	AForm*	makeSC(std::string target);
	int		getFormNum(std::string name);
public:
	Intern();
	Intern(const Intern& intern);
	~Intern();
	Intern& operator = (const Intern& intern);

	AForm*	makeForm(std::string name, std::string target);

	class FormNotFoundException{
	public:
		FormNotFoundException(std::string file, int line) {
			std::stringstream ss;
			ss << "\e[30m" << file << ":" << line << std::endl << "\e[31mINTERN EXCEPTION: FORM NOT FOUND!!\e[0m";
			throw std::runtime_error(ss.str().c_str());
		}
	};
};

typedef AForm* (Intern::*function_p)(std::string target);

#endif
