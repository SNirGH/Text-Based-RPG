#pragma once

#include "Potion.hpp"
#include "../Player/Player.hpp"

class HealthPotion final : public Potion {
public:
	HealthPotion(const std::string& name, const std::string& description, float percent, uint8_t amount)
		: Potion(name, description, percent, amount, PotionEffect::Health) {}
};