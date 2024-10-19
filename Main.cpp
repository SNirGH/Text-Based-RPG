#include <iostream>
#include <conio.h>

#include "Player/Mage.hpp"
#include "Weapons/Dagger.hpp"
#include "Potions/ManaPotion.hpp"
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

	std::unique_ptr<Mage> player = std::make_unique<Mage>();

	std::unique_ptr<Weapon> dagger = std::make_unique<Dagger>(
		"Fire Dagger",
		"A dagger created from a volcano.",
		25.0F,
		Effects::Fire
	);
	

	std::unique_ptr<ManaPotion> mana = std::make_unique<ManaPotion>(
		"Mana Potion",
		"This will restore your mana.",
		0.25F,
		2
	);
	
	std::unique_ptr<HealthPotion> health_25 = std::make_unique<HealthPotion>(
		"Health Potion (25%)",
		"This will restore your health.",
		0.25F,
		2
	);
	
	std::unique_ptr<HealthPotion> health_50 = std::make_unique<HealthPotion>(
		"Health Potion (50%)",
		"This will restore your health.",
		0.50F,
		2
	);
	std::unique_ptr<HealthPotion> health_100 = std::make_unique<HealthPotion>(
		"Health Potion (100%)",
		"This will restore your health.",
		1.0F,
		2
	);

	player->printStats();

	player->addItemToInventory(std::move(health_25));
	player->addItemToInventory(std::move(health_50));
	player->addItemToInventory(std::move(health_100));

	player->TakeDamage(player->getHealth() * 0.25F);
	player->printStats();

	player->UsePotion(player->getItemFromInventory("Health Potion (25%)"), *player);
	player->printStats();

	player->TakeDamage(player->getHealth() * 0.50F);
	player->printStats();

	player->UsePotion(player->getItemFromInventory("Health Potion (50%)"), *player);
	player->printStats();

	player->TakeDamage(player->getHealth() * 1.0F);
	player->printStats();

	player->UsePotion(player->getItemFromInventory("Health Potion (100%)"), *player);
	player->printStats();

	player->addItemToInventory(std::move(dagger));
	player->addItemToInventory(std::move(mana));

	player->printStats();

	player->listItemsInInventory();


	(void)_getch();
}