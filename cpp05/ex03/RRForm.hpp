#ifndef __RRFORM__
#define __RRFORM__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RRForm : public AForm
{
private:
	std::string _target;
public:
	RRForm(std::string target);
	RRForm(const RRForm& rrform);
	~RRForm();
	RRForm& operator = (const RRForm& rrform);

	void		printExecMessage() const;
};

#endif
