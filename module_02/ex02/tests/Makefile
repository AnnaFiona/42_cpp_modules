NAME = test

CXX = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	../Fixed.cpp \
		arithmetric_tests.cpp \
		comparison_tests.cpp \
		in-decrement_tests.cpp \
		min_max_tests.cpp \
		oor_numbers_tests.cpp \
		test.cpp

OBJ = $(SRC:.cpp=.o)

DEP = $(SRC:.cpp=.d)

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)
	./test

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