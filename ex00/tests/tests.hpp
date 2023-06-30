#pragma once

# include "../Animal.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <stdlib.h> // allowed?

//AnimalTests.cpp
void	animal_tests();

//tests.cpp
void	    ok();
void	    fail();
void	    compare(const char *test, int my_output, int right_output, char last);
std::string	get_right_output(char *right_output_file);
