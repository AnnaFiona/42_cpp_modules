#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <algorithm> //allowed?
# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	_Name;
		int			_HitPoints;
		int			_EnergyPoints;
		int			_AttackDamage;

	public:
	//con- and destructors
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &C);
		ClapTrap	&operator = (const ClapTrap C);
		~ClapTrap();

	//getters
		int		get_HitPoints() const;
		int		get_EnergyPoints() const;
		int		get_AttackDamage() const;
	//setters
		void	set_HitPoints(const unsigned int hit_points);
		void	set_EnergyPoints(const unsigned int energy_points);
		void	set_AttackDamage(const unsigned int attack_damage);

	//member-functions
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

//ClapTrapTests.cpp
void	clap_trap_tests(std::ofstream &file);

//tests.cpp
void	ok(std::ofstream &file);
void	fail(std::ofstream &file);
void	compare(std::ofstream &file, const char *test, int my_output, int right_output, char last);


#endif