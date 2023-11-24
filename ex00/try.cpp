#include "BitcoinExchange.hpp"


pair	process_data_line(line)
	splits line at ','
	checks syntax
		throw syntax error
	if (!is_valid_time(string time))
		throw syntax error
	check_value(string_value) //throws error

void	get_data(&map, db_name) 
	opens db
	throw: couldnt open db
	checks first line
	throw: syntax error
	loop
		//read line from db
		process_data_line(line); //returns pair and checks line
			throws: syntax error
					out of range value
					non-existant date
	close file



float	get_rate(&map, pair) //
{
	get value from map
	return (multiply values)
}


pair	process_infile_line(string line) 
	splits line
	checks syntax
	throw: syntax error

	check_time(string time) //throws error //checks
	if check_value(string value) //returns bool //checks
		throw: syntax error
	return (pair)

void	print_exchange(&map, infile_name) //
	opens infile
	throw: couldnt open file
	checks first line
	throw: syntax error
	loop
		read line from infile
		try: process_infile_line(line); //returns pair and checks line
				throws: syntax error
					out of range value
					non-existant date
			 get_rate(&map, pair)
			 print line + rate
		catch: print error message
	close file

void	BitcoinExchange_(db_name, infile_name) //
	try: get_data(&map, db_name) //fills map with data from db
		 print_exchange(&map, infile_name)
	catch: print error message
	throw: none
