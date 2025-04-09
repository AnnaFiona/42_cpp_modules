#include "FtSed.hpp"

//constructor
FtSed::FtSed(char **argv)
{
	this->_FileName = argv[1];
	this->_ToReplace = argv[2];
	this->_Replacement = argv[3];
	this->_FileContent = "";
}


//member-functions
void	FtSed::read_file()
{
	std::ifstream	file;
	std::string		temp;

	file.open(this->_FileName);
	if (!file)
	{
		std::cout << "Error: file '" << _FileName << "' not found" << std::endl;
		exit(1);
	}
	while (!file.eof())
	{
		std::getline(file, temp);
		temp += '\n';
		this->_FileContent += temp;
	}
	this->_FileContent = this->_FileContent.substr(0, this->_FileContent.size() - 1);
	file.close();
}

void	FtSed::replace()
{
	std::string	replaced_content;
	int			x = 0;
	int			y = 0;

	while (this->_FileContent[x])
	{
		y = 0;
		while (this->_FileContent[x + y] && this->_ToReplace[y] && \
				this->_FileContent[x + y] == this->_ToReplace[y])
			y++;
		if (y == (this->_ToReplace.length()))
		{
			replaced_content += this->_Replacement;
			x += this->_ToReplace.length();
		}
		else
		{
			replaced_content += _FileContent[x];
			x++;
		}
	}
	this->_FileContent = replaced_content;
}

void	FtSed::write_to_file()
{
	std::ofstream	file;
	std::string		new_file_name = _FileName + ".replace";

	file.open(new_file_name);
	if (!file)
	{
		std::cout << "Error: could not open '" << new_file_name << "'" << std::endl;
	}
	file << this->_FileContent;
	file.close();
}
