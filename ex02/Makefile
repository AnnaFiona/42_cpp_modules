NAME = brain

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Werror -Wextra $(OBJ) -std=c++98 -o $(NAME)

clean:
	@rm -f $(OBJ)
	@echo all .o-files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the $(NAME) too

re: fclean all