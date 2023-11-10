#include "Harl.hpp"

Harl::Harl(){
	return ;
}

Harl::~Harl(){
	return ;
}

void	Harl::debug(void){
	std::cout << "{DEBUG} I loved when the cluster map was working, It was so nice to see where people sat." << std::endl << std::endl;
}

void	Harl::info(void){
	std::cout << "{INFO} Nevermind cluster map, evaluation poits are a scam, why can't we get more." << std::endl << std::endl;
}

void	Harl::warning(void){
	std::cout << "{WARNING} Is there a way to be able to work in this loud enviroent, i can't hear a thing in my head." << std::endl << std::endl;
}

void	Harl::error(void){
	std::cout << "{ERROR} EUDALD, intra is broken again. C'mon it shouldnt't be that hard to fix." << std::endl << std::endl;
}

int	Harl::getLevel(std::string level){
	std::string	commands[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++){
		if (!level.compare(commands[i]))
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level){
	int	num = getLevel(level);
	if (num == -1){
		std::cout << "{INVALID} Probably complaining about insignificant problems." << std::endl;
		return ;
	}
	function_p	levels[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	(this->*(levels[num]))();

}
