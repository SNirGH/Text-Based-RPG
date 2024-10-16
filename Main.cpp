#include <iostream>
#include <conio.h>

#include "Inventory/Inventory.hpp"
#include "Weapons/Dagger.hpp"

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

	std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>();

	std::unique_ptr<Weapon> dagger = std::make_unique<Dagger>(
		"Fire Dagger",
		"A dagger created from a volcano.",
		25.0F,
		Effects::Fire
	);

	dagger->printWeaponStats();

	std::println("\n-- Inventory --");
	inventory->addToInventory(std::move(dagger));
	inventory->listItems();

	(void)_getch();
}