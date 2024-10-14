#include <iostream>
#include <conio.h>

#include "Player/Player.hpp"
#include "Player/Mage.hpp"
#include "Player/Assassin.hpp"
#include "Player/Warrior.hpp"
#include "Inventory/Inventory.hpp"
#include "Inventory/Item.hpp"
#include "Weapons/Weapon.hpp"
#include "Potions/Potion.hpp"
#include "Status Effects/StatusEffects.hpp"

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
	std::shared_ptr<Item> wand = std::make_shared<Weapon>(
		"Wand",
		"This is a Wand",
		25,
		Effects::Poisoned
	);
	std::shared_ptr<Item> axe = std::make_shared<Weapon>(
		"Axe",
		"This is a axe",
		10,
		Effects::Poisoned
	);
	
	std::shared_ptr<Item> healing = std::make_shared<Potion>(
		"Healing Potion",
		"This will heal you by 25%",
		(float)25.0,
		2,
		PotionEffect::Heal
	);
	
	std::shared_ptr<Item> manapotion = std::make_shared<Potion>(
		"Mana Restoring Potion",
		"This will restore you mana by 25%",
		(float)25.0,
		2,
		PotionEffect::RestoreMana
	);

	inventory.addToInventory(ItemType::Weapon, dagger);
	inventory.addToInventory(ItemType::Weapon, wand);
	inventory.addToInventory(ItemType::Weapon, axe);
	inventory.addToInventory(ItemType::Potion, healing);
	inventory.addToInventory(ItemType::Potion, manapotion);

	inventory.listItems();

	(void)_getch();
}