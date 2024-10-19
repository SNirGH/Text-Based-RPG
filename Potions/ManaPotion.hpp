#pragma once

#include "Potion.hpp"

class ManaPotion final : public Potion {
public:
	ManaPotion(const std::string& name, const std::string& description, float percent, uint8_t amount)
		: Potion(name, description, percent, amount, PotionEffect::Mana) {}

	void Use(Player& player) {
		if (amount == 0) {
			std::println("You have no more Mana Potions");
			return;
		}
		player.RestoreMana(percent);
		amount -= 1;
	}
};

