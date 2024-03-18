#include "RPN.hpp"

RPN::RPN(std::string expression) : _expression(expression){
	for (std::string::const_iterator it = _expression.begin(); it != _expression.end(); it++) {
		char c = *it;
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (_data.size() < 2)
				throw std::invalid_argument("Not enough operands for operator.");
			float a = _data.top();
			_data.pop();
			float b = _data.top();
			_data.pop();
			if (c == '+')
				_data.push(b + a);
			else if (c == '-')
				_data.push(b - a);
			else if (c == '*')
				_data.push(b * a);
			else if (c == '/')
				_data.push(b / a);
		}
		else if (c == ' ')
			continue;
		else if (isdigit(c))
			_data.push(c - '0');
		else
			throw std::invalid_argument("Invalid character in expression.");
	}
	std::cout << "Result: " << _data.top() << std::endl;
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
	(void)other;
	return (*this);
}
