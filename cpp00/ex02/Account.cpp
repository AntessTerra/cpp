// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thr Nov 09 17:30:06 2023                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ){
	this->_nbDeposits = 0;
	this->_nbWithdrawals= 0;
	this->_accountIndex = this->getNbAccounts();
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
	"amount:" << _amount << ";created" << std::endl;
	return ;
}

int	Account::getNbAccounts( void ){
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";" <<
	"total:" << Account::getTotalAmount() << ";" <<
	"deposits:" << Account::getNbDeposits() << ";" <<
	"withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit ){
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
	"p_amount:" << p_amount << ";" <<
	"deposit:" << deposit << ";" <<
	"amount:" << _amount << ";" <<
	"nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	int	p_amount = _amount;
	if (p_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";" <<
		"p_amount:" << p_amount << ";" <<
		"withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
	"p_amount:" << p_amount << ";" <<
	"withdrawal:" << withdrawal << ";" <<
	"amount:" << _amount << ";" <<
	"nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const{
	return (_amount);
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
	"amount:" << _amount << ";" <<
	"deposits:" << _nbDeposits << ";" <<
	"withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
	char	foo[24];
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	std::strftime(foo, sizeof(foo), "[%Y%m%d_%H%M%S] ", now);
	std::cout << foo;
}

Account::~Account(){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" <<
	"amount:" << _amount << ";closed" << std::endl;
	return ;
}

