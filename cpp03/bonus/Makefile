NAME =	dia
CPPFLAGS = -Wall -Wextra -Werror -g -Wshadow -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CPPFLAGS) -o $@ $^ -lncurses

clean:

fclean:
	@rm -f $(NAME)

re:	fclean
	@make all

.PHONY: re, fclean, clean
