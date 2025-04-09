#include "tests.hpp"

void	clap_trap_tests(std::ofstream &file)
{
	ClapTrap	one("one");
	ClapTrap	two("two");

	one.attack("two");
	two.takeDamage(2);
	compare(file, "ClapTrap:", one.get_EnergyPoints(), 9, 'n');
	compare(file, NULL, two.get_HitPoints(), 8, 'n');
	for (int x = 0; x < 10; x++)
		one.beRepaired(1);
	compare(file, NULL, one.get_EnergyPoints(), 0, 'n');
	compare(file, NULL, one.get_HitPoints(), 19, 'n');
}