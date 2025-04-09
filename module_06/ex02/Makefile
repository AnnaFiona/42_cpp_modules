NAME = identify

CXX = c++
CXXFLAGS = -g -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp Base.cpp

OBJDIR = ./objects_and_dependencies/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

DEP =	Base.hpp A.hpp B.hpp C.hpp

.PHONY: clean fclean all re run

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
