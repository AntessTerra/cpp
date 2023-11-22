NAME =	clappy
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp ClapTrap.cpp
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
