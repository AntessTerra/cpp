#ifndef __RPN__
#define __RPN__

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <algorithm>


class RPN
{
private:
	std::stack<float>	_data;
	std::string			_expression;
public:
	RPN(std::string expression);
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);

	float	getFinalValue(void);
};

#endif
