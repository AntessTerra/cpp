#ifndef __CLAPTRAP__
#define __CLAPTRAP__

#include <iostream>
#include <ncurses.h>

class ClapTrap
{
private:
	std::string	_name;
	static const int	_hp = 10, _ep = 10, _ad = 0;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& clap);
	~ClapTrap();
	ClapTrap&	operator = (const ClapTrap &clap);

	void			consoleLog(WINDOW *w, int x, int y, std::string message);
	void			display(WINDOW *w, int x, int y, std::string message);
	std::string		getName() const;
	int				getHitPoints() const;
	int				getEnergyPoints() const;
	int				getAttackDamage() const;
};

#define CONSTRUCTOR "                  :                               \n\
                  :                               \n\
                  .                               \n\
                  .                               \n\
                  .                               \n\
                  .      ...:::.                  \n\
      .~7??^~^.:^~~^^^^::!~JYYJ7:                 \n\
      :?Y55?~!:.:^^::^:.:~7PP55?:                 \n\
       7Y7757~^.^^7YJ~^.^~YPP5Y~.                 \n\
      .~5GGG5^^.:^JBG7:.^7GGPPY^^.                \n\
     .::YBBBBP7!^::^:::7YB#BBBB~.:.               \n\
    ..  ?####&B??7!77??7B#####B:  .               \n\
   .   .^B####&P^^~!~^^7#BBBB#Y:                  \n\
     .^^.?GBGGGP~:!??~^?GGPGP5~^^:                \n\
    .^:. .?PPPGG7:^!!^^?5PP5Y!. :^^:              \n\
   .^:.   !5PPP5?~~~~~~!?555?~.  .:^^.            \n\
  .^:     :?YY7^^^~~~~~^^!JJ~:     .:^:           \n\
 :~:      .~77:::^~~~~~^::!?~:       .^^.         \n\
^!^        :!~::::^^^^^^^^^~^:         ^!:        \n\
 ~!.:      .!7::^^~!!~!!^^:^^:          .^!~  .   \n\
 ^7:..      ^~:::::^^^^^:^:^:.          .^~7~^^^:.\n\
 ~^         .:::::::::::::^::            .^^~!....\n\
 ::          :.~^:::^^::.7::.                .    \n\
             .:!~^~^^^~^:?::.                     \n\
              ..:^~~^^^^:.:.                      \n\
                ::^^^^^::.                        \n\
                .:^:::::..                        \n\
                ..::::::.                         \n\
                 ...:....                         "

#define DESTRUCTOR "                                                  \n\
                                                  \n\
                                 .   .:           \n\
       .:                       .:  :~            \n\
        ~^                     .^. ~~  . ..       \n\
         7^  :               :.!::7! .:.:.        \n\
         .Y^ :: .        :^:::!~^J~.^:::          \n\
        ..~5^ ~....::. .^~~~7!?~J~^!^^.           \n\
       ..:^JP^.!^~!7!~~~~^^^~~~!~~!~:             \n\
        .:^YGP!~!7777~^~^7!!~!~^~!~^....          \n\
        .:~!55Y~7!!7??^~!?JJJ??7?!~^:..           \n\
          .!???77!?J~~^^^~!~7J5J7~^~:..           \n\
           .^7!!?7J7~~^~!7~7Y5J77!~7^^^^::::^^^:. \n\
       .::^~~!!!~!!JJ!?Y5YPG5?~~~~!7~????7!~^:.   \n\
 :^^~~^^!?7!~~7!!~?GPPBBBBG57!!!777!~~!!^::..     \n\
   .:^!??7~~^^7YPP5#&&&&#BPYJ?777!!!~!:.          \n\
     .:^77^^~!J5PB@&&@@@&B5J?7!!~!!!!!^.          \n\
   .   :!7~!~^7YYG&&&@&#GY?77777777!^^^. .        \n\
      .^!7!~~!Y55B#####P5Y?7!!!77~~^^^^:.         \n\
        .~~~~!?7YG?JJ755J?7!~!?7!^^::^~!^.        \n\
         ^~!~^7J??^^^^7~!!~~^~~~!~^^^~~:          \n\
        .  .^~!~^:::^^^^~~~!~^~~~~~^^^:           \n\
               ..  .....^~!!!~::^^^:. ...         \n\
                         ......                   "

#endif
