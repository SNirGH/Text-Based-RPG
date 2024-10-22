#include <iostream>
#include <conio.h>

#include "Potions/PotionFactory.hpp"
#include "Weapons/WeaponFactory.hpp"
#include "Player/PlayerFactory.hpp"
#include "Inventory/Inventory.hpp"

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

	WeaponFactory weaponFactory;
	PotionFactory potionFactory;

	std::unique_ptr<Weapon> dagger = weaponFactory.createDagger("\033[38;2;13;130;240mStun Dagger\033[0m", "Will stun ya", WeaponDebuffs::Stunned);
	std::unique_ptr<Weapon> sword = weaponFactory.createSword("Poison Sword", "Very poisonous sword", WeaponDebuffs::Poisoned);
	std::unique_ptr<Weapon> staff = weaponFactory.createStaff("Fire Staff", "Shoots fireballs", WeaponDebuffs::Fire);

	std::unique_ptr<HealthPotion> healthPotion = potionFactory.createMediumHealthPotion();
	std::unique_ptr<HealthPotion> shealthPotion = potionFactory.createSmallHealthPotion();
	std::unique_ptr<ManaPotion> manaPotion = potionFactory.createMediumManaPotion();
	std::unique_ptr<ManaPotion> smanaPotion = potionFactory.createSmallManaPotion();

	auto player = PlayerFactory::createMage();

	player->AddItemToInventory(std::move(dagger));
	player->AddItemToInventory(std::move(sword));
	player->AddItemToInventory(std::move(staff));
	player->AddItemToInventory(std::move(healthPotion));
	player->AddItemToInventory(std::move(manaPotion));
	player->displayInventory();

	std::println();

	player->RemoveItemFromInventory(5);
	player->RemoveItemFromInventory(3);
	player->RemoveItemFromInventory(1);
	player->AddItemToInventory(std::move(smanaPotion));
	player->AddItemToInventory(std::move(shealthPotion));
	player->displayInventory();

	std::println();
	player->printStats();
	player->GainXP(5000);
	player->printStats();


	(void)_getch();
}