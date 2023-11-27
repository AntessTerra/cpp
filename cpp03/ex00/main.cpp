#include "ClapTrap.hpp"

#include <cstdlib>
#include <unistd.h>

#if GRAPHICS
WINDOW				*map, *console, *info;
std::stringstream	logs, image;
int					row, col;

WINDOW	*create_newwin(int height, int width, int starty, int startx){
	WINDOW *win;
	win = newwin(height, width, starty, startx);
	box(win, 0 , 0);
	wrefresh(win);

	return (win);
}

void	redraw(const ClapTrap &clappy){
	delwin(map);
	delwin(info);
	delwin(console);
	map = create_newwin(0.8*row, 0.75*col, 0, 0);
	console = create_newwin(0.22*row, 0.75*col, 0.8*row, 0);
	info = create_newwin(row, 0.25*col, 0, 0.75*col);
	mvwprintw(map, 0, 0, "%s", image.str().c_str());
	std::stringstream	mess, tmp(logs.str());
	std::string			line;
	int					i = 0;
	while (std::getline(tmp, line)){
		mess << line << std::endl;
		i++;
	}
	while (i > 0){
		std::getline(mess, line);
		if (i == 1){
			mvwprintw(console, i, 1, "%s", line.c_str());
			mvwchgat(console, i, 1, -1, A_BOLD, 0, NULL);
		}
		else{
			mvwprintw(console, i, 1, "%s", line.c_str());
			mvwchgat(console, i, 1, -1, A_DIM, 0, NULL);
		}
		i--;
	}
	mvwprintw(info, 1, 1, "%s", clappy.getName().c_str());
	mvwchgat(info, 1, 1, -1, A_BOLD, 0, NULL);
	mvwprintw(info, 3, 1, "%s: %i", "Hit Ponits", clappy.getHitPoints());
	mvwchgat(info, 3, 1, -1, NULL, 1, NULL);
	mvwprintw(info, 4, 1, "%s: %i", "Energy Points", clappy.getEnergyPoints());
	mvwchgat(info, 4, 1, -1, NULL, 2, NULL);
	mvwprintw(info, 5, 1, "%s: %i", "Attack Damage", clappy.getAttackDamage());
	mvwchgat(info, 5, 1, -1, NULL, 3, NULL);
	box(map, 0, 0);
	wrefresh(map);
	box(console, 0, 0);
	wrefresh(console);
	box(info, 0, 0);
	wrefresh(info);
	return ;
}

int	main(){
	int ch;
	ClapTrap	clappy("Steven");

	initscr();
	if(has_colors() == FALSE){
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	getmaxyx(stdscr, row, col);
	cbreak();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	refresh();
	map = create_newwin(0.8*row, 0.75*col, 0, 0);
	console = create_newwin(0.22*row, 0.75*col, 0.8*row, 0);
	info = create_newwin(row, 0.25*col, 0, 0.75*col);
	redraw(clappy);
	while((ch = getch()) != KEY_F(1)){
		switch(ch){
			case 97:
				clappy.attack("Fred");
					break;
			case 100:
				clappy.takeDamage(1);
					break;
			case 114:
				clappy.beRepaired(1);
					break;
		// default:
				// printw("\nThe pressed key is %i",ch);
		}
		// mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
		redraw(clappy);
	}
	clappy.~ClapTrap();
	redraw(clappy);
	sleep(2);
	endwin();
	exit_curses(0);

	return 0;
}
#else
int	main(){
	ClapTrap	clappy("Steven");

	clappy.attack("Fred");
	clappy.takeDamage(5);
	clappy.beRepaired(3);

	return 0;
}
#endif

