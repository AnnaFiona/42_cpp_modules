#ifndef TESTS_HPP
# define TESTS_HPP

# include "../ClapTrap.hpp"
# include <fstream>


//ClapTrapTests.cpp
void	clap_trap_tests(std::ofstream &file);

//tests.cpp
void	ok(std::ofstream &file);
void	fail(std::ofstream &file);
void	compare(std::ofstream &file, const char *test, int my_output, int right_output, char last);

#endif