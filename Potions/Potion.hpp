#pragma once

#include <string>

#include "../Inventory/Item.hpp"
#include "../Status Effects/StatusEffects.hpp"

enum class PotionEffect {
	Health,
	Mana
};

class Potion : public Item {
public:
	Potion(const std::string& name, const std::string& description, float percent, uint8_t amount, PotionEffect pEffect)
		: Item(name, description, ItemType::Potion),
		percent(percent), amount(amount), potionEffect(pEffect) {}

protected:
	float percent;
	uint8_t amount;
	PotionEffect potionEffect;
};