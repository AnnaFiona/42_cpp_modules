#pragma once

# include "../Animal.hpp"
# include <iostream>
# include <fstream>
# include <string>
# include <stdlib.h> // allowed?

//AnimalTests.cpp
void	animal_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	animal_tests();

//compare_functions.cpp
void		compare(const char *test, const int my_output, const int right_output, const char last);
void		compare(const char *test, const std::string my_output, const std::string right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf , \
					const char *test, const int my_output, const int right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf , \
					const char *test, const std::string my_output, const std::string right_output, const char last);

//tests_utils.cpp
void	    ok();
void	    fail();
void		constructor_tests_framework(void (*constructor_tests)(std::streambuf*, std::streambuf*), \
				const char *my_outfile_name, const char *right_outfile_name, const char *compare_prompt);
std::string	get_file_content(const char *right_output_file);
