#include "tests.hpp"

void	diamond_trap_tests(std::ofstream &file)
{
	DiamondTrap	one("one");
	DiamondTrap	two("two");

	one.attack("two");
	two.takeDamage(30);
	compare(file, "DiamondTrap:", one.get_EnergyPoints(), 49, 'n');
	compare(file, NULL, two.get_HitPoints(), 70, 'n');
	for (int x = 0; x < 10; x++)
		one.beRepaired(1);
	compare(file, NULL, one.get_EnergyPoints(), 39, 'n');
	compare(file, NULL, one.get_HitPoints(), 110, 'n');
	one.highFivesGuys();
	file << std::endl;
}