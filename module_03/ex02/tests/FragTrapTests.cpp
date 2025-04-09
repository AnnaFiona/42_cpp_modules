#include "tests.hpp"

void	frag_trap_tests(std::ofstream &file)
{
	FragTrap	one("one");
	FragTrap	two("two");

	one.attack("two");
	two.takeDamage(30);
	compare(file, "FragTrap:", one.get_EnergyPoints(), 99, 'n');
	compare(file, NULL, two.get_HitPoints(), 70, 'n');
	for (int x = 0; x < 10; x++)
		one.beRepaired(1);
	compare(file, NULL, one.get_EnergyPoints(), 89, 'n');
	compare(file, NULL, one.get_HitPoints(), 110, 'n');
	one.highFivesGuys();
	file << std::endl;
}