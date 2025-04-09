NAME = account

SRC =	Account.cpp \
		tests.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Werror -Wextra -std=c++98 $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all