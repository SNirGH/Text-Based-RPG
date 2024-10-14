#pragma once

#include "../Status Effects/StatusEffects.hpp"

#include <unordered_map>
#include <string>

enum class ItemType {
	Weapon,
	Potion
};

enum class PotionEffect {
	Heal,
	RestoreMana
};

class Item {
public:
	Item(const std::string& name, const std::string& description, uint8_t baseDamage, Effects debuff, ItemType itemType)
		: name(name), description(description), baseDamage(baseDamage),
		  currentDamage(baseDamage), debuff(debuff), itemType(itemType) {}
	
	Item(const std::string& name, const std::string& description, float percent, uint8_t amount, PotionEffect pEffect, ItemType itemType)
		: name(name), description(description), baseDamage(baseDamage),
		  currentDamage(baseDamage), debuff(debuff), itemType(itemType) {}

	std::string getName() const { return name; }
	ItemType getType() const { return itemType; }

protected:
	std::string name, description;
	uint8_t baseDamage, currentDamage;
	float percent;
	uint8_t amount;
	PotionEffect pEffect;
	Effects debuff;
	ItemType itemType;
};