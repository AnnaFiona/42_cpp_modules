#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>

//PmergeMe.cpp
void	insert_every_second_element(std::vector<int>& main_chain, std::vector<int>& v, const int element_size);
void	insert_element(std::vector<int>& main_chain, std::vector<int>::const_iterator mc_end, std::vector<int>::const_iterator element_end, const int element_size);
void	binary_search_insert(std::vector<int>& main_chain, std::vector<int>& v, const int element_size);
void	sort_pairs(std::vector<int>& v, int element_size);
void	fj_vector(std::vector<int>& v, int element_size);


//tests.cpp
void	print_vector(std::vector<int> v);