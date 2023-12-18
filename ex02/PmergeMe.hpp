#pragma once

#include <sys/time.h>
#include <exception>
#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <list>

//PmergeMe.cpp
void	PmergeMe(const int argc, const char **arr);

//PmergeMeList.cpp
void	sort_pairs(std::list<unsigned>& l, const int element_size);
void	insert_every_second_element(std::list<unsigned>& main_chain, std::list<unsigned>& l, const int element_size);
void	insert_element(std::list<unsigned>& main_chain, std::list<unsigned>::const_iterator mc_end, std::list<unsigned>::const_iterator element_num, const int element_size);
void	binary_search_insert(std::list<unsigned>& main_chain, std::list<unsigned>& l, const int element_size);
void	sort_elements(std::list<unsigned>& l, const int element_size);
void	fj_list(std::list<unsigned>& l, int element_size);

//PmergeMeListUtils.cpp
int		size(std::list<unsigned> l);
int		get_working_size(std::list<unsigned>::const_iterator begin, std::list<unsigned>::const_iterator end);
std::list<unsigned>::const_iterator	subtract_it(std::list<unsigned>::const_iterator it, int subtract);
std::list<unsigned>::iterator	subtract_it(std::list<unsigned>::iterator it, int subtract);
std::list<unsigned>::const_iterator	add_it(std::list<unsigned>::const_iterator it, int add);
std::list<unsigned>::iterator	add_it(std::list<unsigned>::iterator it, int add);

//PmergeMeVector.cpp
void	sort_pairs(std::vector<unsigned>& v, int element_size);
void	insert_every_second_element(std::vector<unsigned>& main_chain, std::vector<unsigned>& v, const int element_size);
void	insert_element(std::vector<unsigned>& main_chain, std::vector<unsigned>::const_iterator mc_end, std::vector<unsigned>::const_iterator element_end, const int element_size);
void	binary_search_insert(std::vector<unsigned>& main_chain, std::vector<unsigned>& v, const int element_size);
void	sort_elements(std::vector<unsigned>& v, const int element_size);
void	fj_vector(std::vector<unsigned>& v, int element_size);
