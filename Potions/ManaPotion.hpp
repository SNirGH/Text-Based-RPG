#pragma once

#include "Potion.hpp"
#include "../Player/Player.hpp"

class ManaPotion final : public Potion {
public:
	ManaPotion(const std::string& name, const std::string& description, float percent, uint8_t amount, Player& player)
		: Potion(name, description, percent, amount, PotionEffect::Mana), player(player) {}

	void Use() override {
		if (!player.findItemInInventory(name)) {
			std::println("You have no more Mana Potions");
			return;
		}
		player.RestoreMana(percent);
		amount -= 1;
		if (amount <= 0)
			player.removeItemFromInventory(name);
	}
private:
	Player& player;
};

