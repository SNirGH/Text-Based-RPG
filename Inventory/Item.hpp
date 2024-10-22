#pragma once

#include <string>
#include <memory>
#include <print>

enum class ItemType : uint8_t { Potion, Weapon };

class Item {
public:
	Item(const std::string& name, const std::string& description, ItemType itemType)
		: name(name), description(description), itemType(itemType) {}

	virtual std::string GetTypeString() const = 0;

	std::string GetName() const { return name; }
	std::string GetDescription() const { return description; }
	ItemType GetItemType() const { return itemType; }

	virtual ~Item() = default;
protected:
	std::string name, description;
	ItemType itemType;
};