#include <fstream>
#include <sstream>
#include <iostream>

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2){
		std::cout << "Invalid number of arguments\nPleasu use like this ./harlFilter <argument_level>" << std::endl;
		return (1);
	}
	int		level = harl.getLevel(argv[1]);
	switch (level) {
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break ;
	default:
		std::cout << "{INVALID} Probably complaining about insignificant problems." << std::endl;
		break ;
	}
	return (0);
}
