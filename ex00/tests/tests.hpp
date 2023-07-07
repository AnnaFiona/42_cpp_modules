#pragma once

# include <iostream>
# include <fstream>
# include <cstdlib> //allowed?
# include <string>


///////testfiles//////////////////////////////////////777
//AnimalTests.cpp
void	animal_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	animal_tests();

//CatTests.cpp
void	cat_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	cat_tests();

//DogTests.cpp
void	dog_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	dog_tests();

//MixedTests.cpp
void	mixed_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	mixed_tests();

//WrongAnimalTests.cpp
void	wrong_animal_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	wrong_animal_tests();

//CatTests.cpp
void	wrong_cat_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf);
void	wrong_cat_tests();

////////////other functions///////////////////////////7777
//compare_functions.cpp
void		compare(const char *test, const int my_output, const int right_output, const char last);
void		compare(const char *test, const std::string my_output, const std::string right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf, \
					const char *test, const int my_output, const int right_output, const char last);
void		compare(std::streambuf *filebuf, std::streambuf *coutbuf, \
					const char *test, const std::string my_output, const std::string right_output, const char last);

//tests_utils.cpp
void	    ok();
void	    fail();
std::string	get_file_content(const char *right_output_file);
void		constructor_tests_framework(void (*constructor_tests)(std::streambuf*, std::streambuf*), \
				const char *my_outfile_name, const char *right_outfile_name, const char *compare_prompt);
