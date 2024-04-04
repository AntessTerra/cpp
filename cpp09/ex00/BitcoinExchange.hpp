#ifndef __BITCOINEXCHANGE__
#define __BITCOINEXCHANGE__

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>

struct s_date {
	int day;
	int month;
	int year;
};

class BitcoinExchange
{
private:
	std::multimap<s_date, float> _data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void printData();
	float getClosestValue(s_date date);
};

#endif
