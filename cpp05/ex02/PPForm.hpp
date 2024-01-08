#ifndef __PPFORM__
#define __PPFORM__

#include <iostream>
#include "AForm.hpp"

class PPForm : public AForm
{
private:
	std::string _target;
public:
	PPForm(std::string target);
	PPForm(const PPForm& ppform);
	~PPForm();
	PPForm& operator = (const PPForm& ppform);
};

#endif
