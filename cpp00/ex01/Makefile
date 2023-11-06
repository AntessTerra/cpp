NAME = phony
CPPFLAGS = -g -std=c++98

SRC = phony.cpp
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
