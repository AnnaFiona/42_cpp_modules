NAME = tests

DEP = tests.hpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	AnimalTests.cpp \
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
	@rm -f $(NAME) test_result.txt
	@echo
	@echo ...and the $(NAME) and test_result.txt too

re: fclean all