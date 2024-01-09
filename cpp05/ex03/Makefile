NAME =	intern
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp PPForm.cpp RRForm.cpp SCForm.cpp Intern.cpp
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
