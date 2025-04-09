NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Werror -Wextra $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@echo all .o-files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the megaphone too

re: fclean all