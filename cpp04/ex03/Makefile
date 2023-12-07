NAME =	interface
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CPPFLAGS) -o $@ $^

clean:

fclean:
	@rm -f $(NAME)

re:	fclean
	@make all

.PHONY: re, fclean, clean
