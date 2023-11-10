#include <sstream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	p;

	while (1)
	{
		int			num, pos;
		std::string	line, command, delim;

		std::getline(std::cin, line);
		std::stringstream ss(line);
		ss >> command >> delim;
		if (!command.compare("EXIT"))
			break ;
		if (!command.compare("ADD"))
			p.addContact();
		if (!command.compare("SEARCH"))
		{
			pos = delim.find_first_of("0123456789");
			if (pos == 0)
			{
				std::stringstream snum(delim.substr(pos));
				snum >> num;
				p.printAtNum(num);
			}
			else if (delim.length() > 0)
				p.printAtString(delim);
			else if (!delim.length())
				p.printAll();
		}
	}
}
