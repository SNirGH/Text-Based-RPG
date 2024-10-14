#pragma once

#include <string>

#include "Item.hpp"
#include "StatusEffects.hpp"

class Weapon : public Item {
public:
	Weapon(const std::string& name, const std::string& description, uint8_t baseDamage, Effects debuff)
		: Item(name, description, baseDamage, debuff, ItemType::Weapon) {}
};