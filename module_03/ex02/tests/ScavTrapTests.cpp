#include "tests.hpp"

void	scav_trap_tests(std::ofstream &file)
{
	ScavTrap	one("one");
	ScavTrap	two("two");

	one.attack("two");
	two.takeDamage(20);
	compare(file, "ScavTrap:", one.get_EnergyPoints(), 49, 'n');
	compare(file, NULL, two.get_HitPoints(), 80, 'n');
	for (int x = 0; x < 10; x++)
		one.beRepaired(1);
	compare(file, NULL, one.get_EnergyPoints(), 39, 'n');
	compare(file, NULL, one.get_HitPoints(), 110, 'n');
    one.guardGate();
	file << std::endl;
}