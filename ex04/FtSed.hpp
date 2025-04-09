#ifndef FT_SED_HPP
# define FT_SED_HPP

# include <iostream>
# include <fstream>
# include <string>

class FtSed
{
	private:
		std::string		_FileName;
		std::string		_ToReplace;
		std::string		_Replacement;
		std::string		_FileContent;

	public:
	//constructor
		FtSed(char **argv);
	
	//member-functions
		void    read_file();
		void	replace();
		void	write_to_file();
};


#endif
