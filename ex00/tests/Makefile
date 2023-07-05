NAME = tests

DEP = tests.hpp ../Animal.hpp ../Cat.hpp ../Dog.hpp ../WrongAnimal.hpp ../WrongCat.hpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	../Animal.cpp \
		../Cat.cpp \
		../Dog.cpp \
		../WrongAnimal.cpp \
		../WrongCat.cpp \
		AnimalTests.cpp \
		CatTests.cpp \
		DogTests.cpp \
		compare_functions.cpp \
		test_utils.cpp \
		tests.cpp \
		WrongAnimalTests.cpp \
		WrongCatTests.cpp

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
	valgrind ./$(NAME)

clean:
	@rm -rf $(OBJDIR) *.o *.d
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME) my_output/*.txt
	@echo
	@echo ...and the $(NAME) and the my_output-files too

re: fclean all