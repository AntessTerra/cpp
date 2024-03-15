#include "BitcoinExchange.hpp"

bool operator<(const s_date& l, const s_date& r) {
	if (l.year < r.year) return true;
	if (l.year > r.year) return false;
	if (l.month < r.month) return true;
	if (l.month > r.month) return false;
	if (l.day < r.day) return true;
	return false;
}

BitcoinExchange::BitcoinExchange() {
	std::string sdate, svalue, line, firstline;
	std::fstream database;

	database.open("data.csv", std::ios::in);
	if (!database.is_open())
		throw std::runtime_error("Error: couldn't open data.csv file.");
	std::getline(database, firstline);
	char delimiter = firstline[firstline.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")];
	while (std::getline(database, line)) {
		std::stringstream ss(line);
		std::getline(ss, sdate, delimiter);
		std::getline(ss, svalue, delimiter);
		s_date date;
		date.day = std::atoi(sdate.substr(8, 2).c_str());
		date.month = std::atoi(sdate.substr(5, 2).c_str());
		date.year = std::atoi(sdate.substr(0, 4).c_str());
		_data.insert(std::pair<s_date, float>(date, std::atof(svalue.c_str())));
	}
	database.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	(void)other;
	return (*this);
}

void	BitcoinExchange::printData() {
	for(std::multimap<s_date, float>::iterator it = _data.begin(); it != _data.end(); ++it)
		std::cout << it->first.year << "-" << it->first.month << "-" << it->first.day << " => " << it->second << std::endl;
}

float	BitcoinExchange::getClosestValue(s_date date) {
	std::multimap<s_date, float>::iterator it = _data.lower_bound(date);
	if (it == _data.begin())
		return it->second;
	if (it == _data.end())
		return (--it)->second;
	std::multimap<s_date, float>::iterator it2 = it;
	return (--it)->second - it2->second > 0 ? it2->second : it->second;
}
