#include "PhoneBook.hpp"

int	main()
{
	PhoneBook p;
	std::string	command;

	while (1)
	{
		std::cin >> command;
		if (!command.compare("EXIT"))
			break ;
		if (!command.compare("SEARCH"))
		{
			p.print(0);
		}
		if (!command.compare("ADD"))
		{
			p.addContact();
		}
	}
}
