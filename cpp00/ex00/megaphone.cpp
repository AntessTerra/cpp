#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	string;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			string = argv[i];
			for (unsigned long j = 0; j < string.length(); j++)
				std::cout << (char)toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
