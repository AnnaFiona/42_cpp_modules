#ifndef  TESTS_HPP
# define TESTS_HPP

#include "../Fixed.hpp"
#include "limits.h"


//arithmetric_tests.cpp
void	arithmetric_tests(void);

//comparison_tests.cpp
void	comparison_tests();

//in-decrement_tests.cpp
void	in_and_decrement_tests();

//min_max_tests.cpp
void	min_max_tests();

//oor_numbers_tests.cpp
void	oor_numbers_tests();

//test.cpp
void	ok(void);
void	fail(void);
void	compare(const char *test, float my_output, float right_output, char last);
void	compare(const char *test, Fixed my_output, Fixed right_output, char last);
void	compare(const char *test, int my_output, int right_output, char last);




#endif