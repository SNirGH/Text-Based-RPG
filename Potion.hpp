#pragma once

#include <string>

#include "Item.hpp"
#include "StatusEffects.hpp"

class Potion : public Item {
public:
	Potion(const std::string& name, const std::string& description, float percent, uint8_t amount, PotionEffect pEffect)
		: Item(name, description, percent, amount, pEffect, ItemType::Potion) {}
};