#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	p;

	while (1)
	{
		int			num, pos;
		std::string	line, command, delim;

		std::getline(std::cin, line);
		// std::cout << "LINE: " << line << std::endl;
		std::stringstream ss(line);
		// while (ss >> command)
		// 	std::cout << command << std::endl;
		ss >> command >> delim;
		// std::cout << command << std::endl;
		if (!command.compare("EXIT"))
			break ;
		if (!command.compare("ADD"))
			p.addContact();
		if (!command.compare("SEARCH"))
		{
			// std::cout << "DELIM: " << delim << std::endl;
			pos = delim.find_first_of("0123456789");
			// std::cout << "POS :" << pos << std::endl;
			if (pos == 0)
			{
				std::stringstream snum(delim.substr(pos));
				snum >> num;
				p.printAtNum(num);
			}
			else if (!delim.length())
				p.printAll();
				// std::cout << num << std::endl;
				// std::cout << command.substr(pos) << std::endl;
			// ss >> num;
			// std::cout << num << std::endl;
			// if (num >= 0 && num <= 7)
				// p.print(num);
		}
	}
}
