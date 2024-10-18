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
	std::string getItemTypeName() const {
		switch (itemType) {
		case ItemType::Weapon:
			return "Weapon";
		case ItemType::Potion:
			return "Potion";
		}
	}
	ItemType getItemType() const { return itemType; }

	virtual ~Item() = default;
protected:
	std::string name, description;
	ItemType itemType;
};