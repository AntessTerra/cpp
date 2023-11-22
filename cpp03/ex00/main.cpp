#include "ClapTrap.hpp"

#include <cstdlib>
#include <unistd.h>
#include <sstream>

WINDOW	*create_newwin(int height, int width, int starty, int startx){
	WINDOW *win;
	win = newwin(height, width, starty, startx);
	box(win, 0 , 0);
	wrefresh(win);

	return (win);
}

int	main(){
	WINDOW	*map, *console, *info;
	int ch, row, col;
	std::cout << "\e[8;25;100t";
	/* Curses Initialisations */
	initscr();
	getmaxyx(stdscr,row,col);
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	refresh();
	map = create_newwin(17, 75, 0, 0);
	console = create_newwin(8, 75, 17, 0);
	info = create_newwin(25, 25, 0, 75);
	ClapTrap	clappy("Steven");
	clappy.consoleLog(console, 1, 1, "Aaaaand... OPEN!");
	clappy.display(map, 1, 1, CONSTRUCTOR);
	std::string	mess = "Hit Points: ", num;
	std::stringstream	ss;
	clappy.display(info, 1, 1, clappy.getName());
	ss << clappy.getHitPoints();
	ss >> num;
	mess.append(num);
	clappy.display(info, 3, 1, mess);
	ss.clear();
	mess = "Energy Points: ";
	ss << clappy.getEnergyPoints();
	ss >> num;
	mess.append(num);
	clappy.display(info, 4, 1, mess);
	ss.clear();
	mess = "Attack Damage: ";
	ss << clappy.getAttackDamage();
	ss >> num;
	mess.append(num);
	clappy.display(info, 5, 1, mess);
	box(map, 0, 0);
	wrefresh(map);
	box(info, 0, 0);
	wrefresh(info);
	box(console, 0, 0);
	wrefresh(console);
	while((ch = getch()) != KEY_F(1)){
		switch(ch){
			case 97:
				printw("\nATTACK");
					break;
			case 100:
				printw("\nTAKE DAMAGE");
					break;
			case 114:
				printw("\nREPAIR");
					break;
		// default:
				// printw("\nThe pressed key is %i",ch);
		}
	}

	clappy.consoleLog(console, 2, 1, "Shutting down!");
	clappy.display(map, 1, 1, DESTRUCTOR);
	box(map, 0, 0);
	wrefresh(map);
	box(info, 0, 0);
	wrefresh(info);
	box(console, 0, 0);
	wrefresh(console);
	sleep(3);
	endwin();
	exit_curses(0);

return 0;
}
