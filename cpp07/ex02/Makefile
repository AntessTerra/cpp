NAME =	array
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp
SRC_BONUS = main_bonus.cpp

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CPPFLAGS) -o $@ $^

clean:

fclean:
	@rm -f $(NAME)

re:	fclean
	@make all

bonus: $(OBJ_BONUS)
	@c++ $(CPPFLAGS) -o $(NAME) $^

.PHONY: re, fclean, clean
