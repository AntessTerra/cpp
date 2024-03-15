#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2)
		return std::cout << "Error: wrong number of arguments.\nUsage ./btc <filename>" << std::endl, 1;
	else {
		try {
			BitcoinExchange btc;
			std::string filename(argv[1]), sdate, svalue, line, firstline;
			std::fstream in;

			in.open(filename.c_str(), std::ios::in);
			if (!in.is_open())
				throw std::runtime_error("Error: file not found.");
			std::getline(in, firstline);
			char delimiter = firstline[firstline.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")];
			while (std::getline(in, line)) {
				std::stringstream ss(line);
				std::getline(ss, sdate, delimiter);
				std::getline(ss, svalue, delimiter);
				s_date date;
				date.day = std::atoi(sdate.substr(8, 2).c_str());
				date.month = std::atoi(sdate.substr(5, 2).c_str());
				date.year = std::atoi(sdate.substr(0, 4).c_str());
				float f = std::atof(svalue.c_str());
				if (date.day > 31 || date.day < 1 || date.month > 12 || date.month < 1 || date.year < 2000 || date.year > 2099)
					std::cerr << "Error: bad input => " << date.year << "-" << date.month << "-" << date.day << std::endl;
				else if (f < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else if (f > 1000)
					std::cerr << "Error: too large number." << std::endl;
				else
					std::cout << date.year << "-" << date.month << "-" << date.day << " => " << f * btc.getClosestValue(date) << std::endl;
			}
			in.close();
		}
		catch(const std::exception& e) { std::cerr << e.what() << '\n';}
	}
	return 0;
}
