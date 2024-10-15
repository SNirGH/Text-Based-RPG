#pragma once

#include <string>

#include "../Inventory/Item.hpp"

class Weapon : public Item {
public:
	Weapon(const std::string& name, const std::string& description, uint8_t baseDamage, Effects debuff)
		: Item(name, description, ItemType::Weapon),
		  baseDamage(baseDamage), currentDamage(baseDamage), debuff(debuff) {}
	
	std::string GetWeaponDebuff(Effects debuff);
protected:
	uint8_t baseDamage, currentDamage;
	Effects debuff;
};