NAME = brain

CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)

DEP = $(SRC:.cpp=.d)

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

-include $(DEP)

%.o: %.cpp
	$(CXX) $(FLAGS) -MMD -MP $< -o $@ -c

clean:
	@rm -f $(OBJ) $(DEP)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the $(NAME) too

re: fclean all