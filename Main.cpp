#include <iostream>
#include <conio.h>

#include "Player/Mage.hpp"
#include "Weapons/Dagger.hpp"
#include "Potions/HealthPotion.hpp"

int main() {
	/*char choice;

	std::unique_ptr<Player> player;

	do {
		std::print("Which class would you like: ");
		choice = _getch();

		switch (choice) {
		case '1':
			player = std::make_unique<Assassin>();
			break;
		case '2':
			player = std::make_unique<Mage>();
			break;
		case '3':
			player = std::make_unique<Warrior>();
			break;
		default:
			std::println("\033[31mInvalid value\033[0m");
			break;
		}
		player->printStats();
		player->printDescription();
		std::println("");
	} while ((choice < 49 or choice > 51) or choice != 'q');*/

	std::unique_ptr<Player> player = std::make_unique<Mage>();

	std::unique_ptr<Weapon> dagger = std::make_unique<Dagger>(
		"Fire Dagger",
		"A dagger created from a volcano.",
		25.0F,
		Effects::Fire
	);
	
	std::unique_ptr<Potion> health = std::make_unique<HealthPotion>(
		"Health Potion",
		"This will heal you.",
		25.0F,
		5
	);

	player->printStats();

	player->TakeDamage(5);

	(void)_getch();
}