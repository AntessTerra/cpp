#ifndef __SCFORM__
#define __SCFORM__

#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include "AForm.hpp"

class SCForm : public AForm
{
private:
	std::string _target;
public:
	SCForm(std::string target);
	SCForm(const SCForm& scform);
	~SCForm();
	SCForm& operator = (const SCForm& scform);

	void		printExecMessage() const;

	class FileNotFoundException{
	public:
		FileNotFoundException(std::string file, int line) {
			std::stringstream ss;
			ss << file << ":" << line << std::endl << "FORM EXCEPTION: FILE NOT FOUND!!";
			throw std::runtime_error(ss.str().c_str());
		}
	};
};

#endif
