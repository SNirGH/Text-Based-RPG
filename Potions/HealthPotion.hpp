#pragma once

#include "Potion.hpp"
#include "../Player/Player.hpp"

class HealthPotion final : public Potion {
public:
	HealthPotion(const std::string& name, const std::string& description, float percent, uint8_t amount, Player& player)
		: Potion(name, description, percent, amount, PotionEffect::Health), player(player) {}

	void Use() override {
		player.RestoreHealth(percent);
	}

private:
	Player& player;
};