#include <iostream>
#include <fstream>

int	printError(std::string error){
	std::cout << error << std::endl;
	return (1);
}

int	main(int argc, char **argv) {
	if (argc != 4)
		return (printError("Wrong number of arguments!!\nUsecase ./sed <filename> to_replace with_what"));
	std::string	filename, s1, s2;
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filename.length() <= 0 && s1.length() <= 0 && s2.length() <= 0)
		return (printError("Some argument is wrong!!"));
	std::fstream	in, out;
	in.open(filename.c_str(), std::ios::in);
	if (!in)
		return (printError("Cannot open file!!"));
	out.open(filename.append(".replace").c_str(), std::ios::out);
	if (!out)
		return (printError("Cannot create out file!!"));
	std::string	word;
	while (in >> word)
		std::cout << word << std::endl;
	in.close();
	out.close();
}
