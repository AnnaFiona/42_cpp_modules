#include "BitcoinExchange.hpp"


pair	process_line(string line)
	splits line
	checks syntax
	throw: syntax error

	check_time(string time) //returns bool //checks
		throw: non-existant date
	if (!is_float(value) && !is_int(value)) //returns bool //utils
		throw: wrong value
	if (value out of range)
		throw: out of range value
	return (pair)


void	get_data(&map, db_name)
	opens db
	throw: couldnt open db
	loop
		//read line from db
		process_line(line); //returns pair and checks line
			throws: syntax error
					out of range value
					non-existant date
					wrong value




void	BitcoinExchange_(db_name, infile_name)
	get_data(&map, db_name) //fills map with data from db
	throw: none
