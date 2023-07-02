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
void	    compare(const char *test, const int my_output, const int right_output, const char last);
void		compare(const char *test, const std::string my_output, const std::string right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf , \
					const char *test, const int my_output, const int right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf , \
					const char *test, const std::string my_output, const std::string right_output, const char last);
std::string	get_file_content(char *right_output_file);
