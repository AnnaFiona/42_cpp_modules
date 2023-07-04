NAME = tests

DEP = tests.hpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	../Animal.cpp \
		AnimalTests.cpp \
		compare_functions.cpp \
		test_utils.cpp \
		tests.cpp

OBJDIR = ./objects_and_dependencies/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

.PHONY: clean fclean all tests

all: $(NAME)

$(OBJDIR)%.o: ./%.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	./$(NAME)

clean:
	@rm -rf $(OBJDIR) *.o *.d
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME) my_output/*.txt
	@echo
	@echo ...and the $(NAME) and the my_output-files too

re: fclean all