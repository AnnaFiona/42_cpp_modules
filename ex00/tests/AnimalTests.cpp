#include "tests.hpp"

void	actual_constructor_tests(std::streambuf *filebuf, std::streambuf *coutbuf)
{
	Animal	Cow("Cow");

	compare(filebuf, coutbuf, "getter:", Cow.getType(), "Cow", 'y');
}

void	constructor_tests()
{
	std::streambuf	*filebuf;
	std::streambuf	*coutbuf;
	std::ofstream	outfile;
	std::string		right_output;
	std::string		my_output;

	outfile.open("my_output/animal.txt", std::ofstream::out);
	if (!outfile)
	{
		std::cout << "Error: could not open file 'my_output/animal.txt'" << std::endl;
		exit (1);
	}
	coutbuf = std::cout.rdbuf();
	filebuf = outfile.rdbuf();

	std::cout.rdbuf(filebuf);
	actual_constructor_tests(filebuf, coutbuf);
	std::cout.rdbuf(coutbuf);

	right_output = get_file_content((char*)"right_output/animal.txt"); //static-cast!!?
	my_output = get_file_content((char*)"my_output/animal.txt");
	outfile.close();
	compare("animal-output:", my_output, right_output, 'y');
}

void    animal_tests()
{
	constructor_tests();
}