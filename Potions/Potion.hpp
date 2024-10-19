#pragma once

#include <string>

#include "../Inventory/Item.hpp"

class Player;

enum class PotionEffect {
	Health,
	Mana
};

class Potion : public Item {
public:
	Potion(const std::string& name, const std::string& description, float percent, uint8_t amount, PotionEffect pEffect)
		: Item(name, description, ItemType::Potion),
		percent(percent), amount(amount), potionEffect(pEffect) {}
	
	uint8_t getAmount() const { return amount; }

	virtual void Use(Player& player) = 0;
protected:
	float percent;
	uint8_t amount;
	PotionEffect potionEffect;
};