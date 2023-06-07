NAME = phonebook

SRC =	Contact.cpp \
		main.cpp \
		PhoneBook.cpp \
		PhoneBook_search.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	c++ -Wall -Werror -Wextra -std=c++98 $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@echo all .o-files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the phonebook too

re: fclean all