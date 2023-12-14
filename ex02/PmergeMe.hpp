#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <list>

//PmergeMe.cpp
void	PmergeMe(const int argc, const char **arr);

//PmergeMeVector.cpp
void	insert_every_second_element(std::vector<unsigned int>& main_chain, std::vector<unsigned int>& v, const int element_size);
void	insert_element(std::vector<unsigned int>& main_chain, std::vector<unsigned int>::const_iterator mc_end, std::vector<unsigned int>::const_iterator element_end, const int element_size);
void	binary_search_insert(std::vector<unsigned int>& main_chain, std::vector<unsigned int>& v, const int element_size);
void	sort_pairs(std::vector<unsigned int>& v, int element_size);
void	fj_vector(std::vector<unsigned int>& v, int element_size);


//tests.cpp
void	print_vector(std::vector<unsigned int> v);