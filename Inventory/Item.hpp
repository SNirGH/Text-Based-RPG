#pragma once

#include <unordered_map>
#include <string>

#include "../Status Effects/StatusEffects.hpp"

enum class ItemType {
	Weapon,
	Potion
};

class Item {
public:
	Item(const std::string& name, const std::string& description, ItemType itemType)
		: name(name), description(description), itemType(itemType) {}

	std::string getName() const { return name; }
	std::string getDescription() const { return description; }
	ItemType getItemType() const { return itemType; }
protected:
	std::string name, description;
	ItemType itemType;
};