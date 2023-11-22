#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name){
	// std::cout << "Aaaaand... OPEN!" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& clap){
	*this = clap;
	return ;
}

ClapTrap::~ClapTrap(){
	// std::cout << "Shutting down!" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator = (const ClapTrap &clap){
	_name = clap._name;
	return (*this);
}

std::string	ClapTrap::getName() const{
	return (_name);
}

int	ClapTrap::getHitPoints() const{
	return (_hp);
}

int	ClapTrap::getEnergyPoints() const{
	return (_ep);
}

int	ClapTrap::getAttackDamage() const{
	return (_ad);
}

void	ClapTrap::consoleLog(WINDOW *w, int x, int y, std::string message){
	mvwprintw(w, x, y, "ClapTrap named %s says: %s\n", _name.c_str(), message.c_str());
	return ;
}

void	ClapTrap::display(WINDOW *w, int x, int y, std::string message){
	mvwprintw(w, x, y, "%s\n", message.c_str());
	return ;
}
