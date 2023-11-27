#include "ScavTrap.hpp"

#include <cstdlib>
#include <unistd.h>

#if GRAPHICS
WINDOW				*map, *console, *info, *menu;
std::stringstream	logs, image;
std::string			choices[] = {
					"(CA) Clap Attack",
					"(CD) Clap Take Damage",
					"(CR) Clap Repair ",
					"(CG) Not Supported",
					"(SA) Scav Attack",
					"(ST) Scav Take Damage",
					"(SR) Scav Repair",
					"(SG) Scav Guard Gate",
					"(F1) Exit",
					};
int					row, col, in_menu = 0, n_choices = sizeof(choices) / sizeof(std::string);

WINDOW	*create_newwin(int height, int width, int starty, int startx){
	WINDOW *win;
	win = newwin(height, width, starty, startx);
	box(win, 0 , 0);
	wrefresh(win);

	return (win);
}

void	redraw(const ClapTrap &clappy, const ScavTrap& scavvy){
	delwin(map);
	map = create_newwin(0.8*row, 0.75*col, 0, 0);

	mvwprintw(map, 0, 0, "%s", image.str().c_str());

	box(map, 0, 0);
	wrefresh(map);

	delwin(info);
	info = create_newwin(row, 0.25*col, 0, 0.75*col);

	mvwprintw(info, 1, 1, "%s", clappy.getName().c_str());
	mvwchgat(info, 1, 1, -1, A_BOLD, 0, NULL);
	mvwprintw(info, 3, 1, "%s: %i", "Hit Ponits", clappy.getHitPoints());
	mvwchgat(info, 3, 1, -1, NULL, 1, NULL);
	mvwprintw(info, 4, 1, "%s: %i", "Energy Points", clappy.getEnergyPoints());
	mvwchgat(info, 4, 1, -1, NULL, 2, NULL);
	mvwprintw(info, 5, 1, "%s: %i", "Attack Damage", clappy.getAttackDamage());
	mvwchgat(info, 5, 1, -1, NULL, 3, NULL);

	mvwprintw(info, 7, 1, "%s", scavvy.getName().c_str());
	mvwchgat(info, 7, 1, -1, A_BOLD, 0, NULL);
	mvwprintw(info, 9, 1, "%s: %i", "Hit Ponits", scavvy.getHitPoints());
	mvwchgat(info, 9, 1, -1, NULL, 1, NULL);
	mvwprintw(info, 10, 1, "%s: %i", "Energy Points", scavvy.getEnergyPoints());
	mvwchgat(info, 10, 1, -1, NULL, 2, NULL);
	mvwprintw(info, 11, 1, "%s: %i", "Attack Damage", scavvy.getAttackDamage());
	mvwchgat(info, 11, 1, -1, NULL, 3, NULL);

	box(info, 0, 0);
	wrefresh(info);

	delwin(console);
	console = create_newwin(0.22*row, 0.75*col, 0.8*row, 0);

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

	box(console, 0, 0);
	wrefresh(console);

	if (in_menu){
		delwin(menu);
		menu = create_newwin(0.4*row, 0.375*col, 0.2*row, 0.1875*col);

		mvwprintw(menu, 1, 1, "Menu");
		mvwchgat(menu, 1, 1, -1, A_STANDOUT, 0, NULL);
		mvwprintw(menu, 2, 1, "%s", clappy.getName().c_str());
		mvwchgat(menu, 2, 1, 0.1875*col, A_BOLD, 2, NULL);
		mvwprintw(menu, 2, 1 + 0.1875*col, "%s", scavvy.getName().c_str());
		mvwchgat(menu, 2, 1 + 0.1875*col, -1, A_BOLD, 3, NULL);
		for (int i = 0; i < n_choices; i++){
			if (i < 4){
				mvwprintw(menu, i + 3, 1, "%s", choices[i].c_str());
			}
			else if (i < 8){
				mvwprintw(menu, i - 1, 1 + 0.1875*col, "%s", choices[i].c_str());
			}
			else {
				mvwprintw(menu, i, 1, "%s", choices[i].c_str());
			}
		}

		box(menu, 0, 0);
		wrefresh(menu);
	}
	return ;
}

int	main(){
	int ch;
	ClapTrap	clappy("Steven");
	ScavTrap	scavvy("Alex");

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
	menu = create_newwin(0.4*row, 0.375*col, 0.2*row, 0.1875*col);
	redraw(clappy, scavvy);
	while((ch = getch()) != KEY_F(1)){
		switch(ch){
			case 10:
				in_menu = 1;
				redraw(clappy, scavvy);
				while((ch = getch()) != 10 && ch != KEY_F(1)){
					switch(ch){
						case 115:
							ch = getch();
							if (ch == 97)
								scavvy.attack(clappy.getName());
							else if (ch == 100)
								scavvy.takeDamage(1);
							else if (ch == 114)
								scavvy.beRepaired(1);
							else if (ch == 103)
								scavvy.guardGate();
							break;
						case 99:
							ch = getch();
							if (ch == 97)
								clappy.attack(scavvy.getName());
							else if (ch == 100)
								clappy.takeDamage(1);
							else if (ch == 114)
								clappy.beRepaired(1);
							else if (ch == 103)
								logs << "ClapTrap " << clappy.getName() << " cannot perform Guard Gate!!" << std::endl;
							break;

					// default:
							// printw("\nThe pressed key is %i",ch);
					}
					// mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
					redraw(clappy, scavvy);
				}
				in_menu = 0;
				break;
		// default:
				// printw("\nThe pressed key is %i",ch);
		}
		// mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
		redraw(clappy, scavvy);
	}
	clappy.~ClapTrap();
	scavvy.~ScavTrap();
	redraw(clappy, scavvy);
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

	ScavTrap	scavvy("Alex");

	scavvy.guardGate();

	return 0;
}
#endif

