#pragma once

#include "Potion.hpp"
#include "../Player/Player.hpp"

class HealthPotion final : public Potion {
public:
	HealthPotion(const std::string& name, const std::string& description, float percent, uint8_t amount, std::unique_ptr<Player> player)
		: Potion(name, description, percent, amount, PotionEffect::Health), player(std::move(player)) {}

	void Use() override {
		player->RestoreHealth(percent);
	}

private:
	std::unique_ptr<Player> player;
};