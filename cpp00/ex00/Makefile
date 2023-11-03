NAME = megaphone
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CPPFLAGS) -o $@ $^

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re:	fclean
	@make all

.PHONY: re, fclean, clean
