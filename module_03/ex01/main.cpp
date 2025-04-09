#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//ex00
/* int	main()
{
	ClapTrap	Herrbert("Herrbert");
	ClapTrap	Norbert("Norbert");
	ClapTrap	Gieselbert;

	Gieselbert.attack("Norbert");
	Norbert.takeDamage(Gieselbert.get_AttackDamage());
	std::cout << "//////////////////////////////////////////////////////" << std::endl;
	Norbert.set_AttackDamage(4);
	Herrbert.attack("Norbert");
	Norbert.takeDamage(Herrbert.get_AttackDamage());
	Norbert.attack("Herrbert");
	Herrbert.takeDamage(Norbert.get_AttackDamage());
	for (int x = 0; x < 10; x++)
		Herrbert.beRepaired(4);
	for (int x = 0; x < 7; x++)
	{
		Norbert.attack("Herrbert");
		Herrbert.takeDamage(Norbert.get_AttackDamage());
	}
	Herrbert.attack("Norbert");
	Herrbert.beRepaired(4);

	std::cout << "//////////////////////////////////////////////////////" << std::endl;
	std::cout << "Herrbert: HP: " << Herrbert.get_HitPoints() << " EP: " << Herrbert.get_EnergyPoints() \
				<< " AT: " << Herrbert.get_AttackDamage() << std::endl;
	std::cout << "Norbert: HP: " << Norbert.get_HitPoints() << " EP: " << Norbert.get_EnergyPoints() \
				<< " AT: " << Norbert.get_AttackDamage() << std::endl;
	Herrbert = Norbert;
	std::cout << "Herrbert: HP: " << Herrbert.get_HitPoints() << " EP: " << Herrbert.get_EnergyPoints() \
				<< " AT: " << Herrbert.get_AttackDamage() << std::endl;
	for (int x = 0; x < 3; x++)
	{
		Herrbert.attack("Norbert");
		Norbert.takeDamage(Herrbert.get_AttackDamage());
	}

	std::cout << "//////////////////////////////////////////////////////" << std::endl;
	ClapTrap	four(Norbert);
	std::cout << "Norbert: HP: " << Norbert.get_HitPoints() << " EP: " << Norbert.get_EnergyPoints() \
				<< " AT: " << Norbert.get_AttackDamage() << std::endl;
	std::cout << "four: HP: " << four.get_HitPoints() << " EP: " << four.get_EnergyPoints() \
				<< " AT: " << four.get_AttackDamage() << std::endl;

	return (0);
} */

int main()
{
	ScavTrap a;
	ScavTrap b("b");
	ScavTrap c("c");
	ScavTrap d(c);

	std::cout << "d: " << d.get_Name() << std::endl;
	d = b;
	std::cout << "d: " << d.get_Name() << std::endl;
	d.set_Name("d");
	std::cout << "d: " << d.get_Name() << std::endl;

	return (0);
}





