#pragma once

# include "../Animal.hpp"
# include <fstream>


//ClapTrapTests.cpp
void	animal_tests(std::ofstream &file);

//tests.cpp
void	ok(std::ofstream &file);
void	fail(std::ofstream &file);
void	compare(std::ofstream &file, const char *test, int my_output, int right_output, char last);
