NAME =	convert
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp ScalarConverter.cpp
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
