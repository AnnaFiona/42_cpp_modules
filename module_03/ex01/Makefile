NAME = scav_trap

DEP = ClapTrap.hpp ScavTrap.hpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	ClapTrap.cpp \
		main.cpp \
		ScavTrap.cpp

OBJDIR = ./objects_and_dependencies/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

.PHONY: clean fclean all

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
	@echo ...and the $(NAME) too

re: fclean all