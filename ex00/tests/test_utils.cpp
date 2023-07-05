#include "tests.hpp"

void	ok()
{
	std::cout << "\033[0;92m OK\033[0m";
}

void	fail()
{
	std::cout << "\033[0;91m FAIL\033[0m";
}

std::string	get_file_content(const char *right_output_file)
{
	std::ifstream	infile(right_output_file, std::ios::in);
	std::string		right_output;
	std::string		buf;

	if (!infile.is_open())
	{
		std::cerr << "Error: file '" << right_output_file << "' could not be opened" << std::endl;
		std::exit (1);
	}
	while (getline(infile, buf))
	{
		right_output += buf + "\n";
	}
	infile.close();
	return (right_output);
}

void	constructor_tests_framework(void (*constructor_tests)(std::streambuf*, std::streambuf*), \
			const char *my_outfile_name, const char *right_outfile_name, const char *compare_prompt)
{
	std::streambuf	*filebuf;
	std::streambuf	*coutbuf;
	std::ofstream	outfile;
	std::string		right_output;
	std::string		my_output;
	
	outfile.open(my_outfile_name, std::ofstream::out);
	if (!outfile)
	{
		std::cout << "Error: could not open file '" << my_outfile_name << \
			"'. Please check if there is a 'my_output' folder in tests. If not, create one" << std::endl;
		std::exit (1);
	}
	coutbuf = std::cout.rdbuf();
	filebuf = outfile.rdbuf();

	std::cout.rdbuf(filebuf);
	constructor_tests(filebuf, coutbuf);
	std::cout.rdbuf(coutbuf);
	outfile.close();

	right_output = get_file_content(right_outfile_name);
	my_output = get_file_content(my_outfile_name);
	compare(compare_prompt, my_output, right_output, 'y');
}
