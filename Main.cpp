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

	std::unique_ptr<Player> player = std::make_unique<Mage>();
	std::cout << player.get() << std::endl;

	std::unique_ptr<Weapon> dagger = std::make_unique<Dagger>(
		"Fire Dagger",
		"A dagger created from a volcano.",
		25.0F,
		Effects::Fire
	);
	

	std::unique_ptr<Potion> mana = std::make_unique<ManaPotion>(
		"Mana Potion",
		"This will restore your mana.",
		0.25F,
		2,
		*player
	);
	
	std::unique_ptr<Potion> health = std::make_unique<HealthPotion>(
		"Health Potion",
		"This will restore your health.",
		0.25F,
		2,
		*player
	);

	player->printStats();

	player->TakeDamage(player->getHealth() * 0.25F);
	player->printStats();
	player->addItemToInventory(std::move(health));


	std::println("{}", player->findItemInInventory(ItemType::Potion, "Health Potion"));
	player->printStats();


	(void)_getch();
}