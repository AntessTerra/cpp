NAME =	RPN
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp RPN.cpp

all: $(NAME)

$(NAME):
	@c++ $(CPPFLAGS) -o $@ $(SRC)

clean:

fclean:
	@rm -f $(NAME)

re:	fclean
	@make all

.PHONY: re, fclean, clean
