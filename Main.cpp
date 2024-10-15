#include <iostream>
#include <conio.h>

#include "Inventory/Inventory.hpp"
#include "Weapons/Weapon.hpp"

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

	Inventory inventory;

	std::shared_ptr<Item> dagger = std::make_shared<Weapon>(
		"Dagger",
		"This is a Dagger",
		30,
		Effects::Poisoned
	);

	dagger->getDescription();
	dagger->getItemType();

	inventory.addToInventory(ItemType::Weapon, dagger);

	inventory.listItems();

	(void)_getch();
}