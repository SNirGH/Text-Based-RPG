#pragma once

#include "Potion.hpp"
#include "../Player/Player.hpp"

class HealthPotion final : public Potion {
public:
	HealthPotion(const std::string& name, const std::string& description, float percent, uint8_t amount, Player& player)
		: Potion(name, description, percent, amount, PotionEffect::Health), player(player) {}

	void Use() override {
		if (!player.findItemInInventory(ItemType::Potion, name)) {
			std::println("You have no more Health Potions");
			return;
		}
		player.RestoreHealth(percent);
		amount -= 1;
		if (amount <= 0)
			player.removeItemFromInventory(ItemType::Potion, name);
	}

private:
	Player& player;
};