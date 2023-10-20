NAME = converter

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

SRC =		main.cpp ScalarConverter.cpp ScalarConverterGetTypes.cpp ScalarConverterPrintU.cpp ScalarConverterPrintUtils.cpp
T_SRC = 	tests.cpp ScalarConverter.cpp ScalarConverterGetTypes.cpp ScalarConverterPrint.cpp ScalarConverterPrintUtils.cpp

OBJDIR = ./objects_and_dependencies/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

T_OBJFILES = $(T_SRC:.cpp=.o)
T_OBJ = $(addprefix $(OBJDIR), $(T_OBJFILES))

DEP =	ScalarConverter.hpp

.PHONY: clean fclean all

all: $(NAME)

$(OBJDIR)%.o: ./%.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

tests: $(OBJDIR) $(T_OBJ)
	$(CXX) $(CXXFLAGS) $(T_OBJ) -o tests
	./tests

clean:
	@rm -rf $(OBJDIR)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME) tests
	@echo
	@echo ...and the executable too

re: fclean all

run: $(NAME)
	./$(NAME)
