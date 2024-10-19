#pragma once

#include "Potion.hpp"

class HealthPotion final : public Potion {
public:
	HealthPotion(const std::string& name, const std::string& description, float percent, uint8_t amount)
		: Potion(name, description, percent, amount, PotionEffect::Health) {}

	void Use(Player& player) {
		if (amount == 0) {
			std::println("You have no more Health Potions");
			return;
		}
		player.RestoreHealth(percent);
		amount -= 1;
	}
};