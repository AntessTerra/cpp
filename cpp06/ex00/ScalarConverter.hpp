#ifndef __SCALARCONVERTER__
#define __SCALARCONVERTER__

#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <sstream>

enum type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

//Static class with private constructor and static methods
class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& scal);
	~ScalarConverter();
	ScalarConverter& operator = (const ScalarConverter& scal);
	static int getType(std::string str);
public:
	static int convert(std::string str);
};

#endif
