NAME = btc

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp BitcoinExchange.cpp BitcoinExchangeUtils.cpp

DEP =	BitcoinExchange.hpp

OBJDIR = ./objects_and_dependencies/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))


.PHONY: clean fclean all re run val

all: $(NAME)

$(OBJDIR)%.o: ./%.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the executable too

re: fclean all

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind ./$(NAME)
