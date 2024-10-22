#pragma once

#include "../Inventory/Item.hpp"
/* MAY POTENTIALLY NEED TO BE REMOVED */
#include "../Player/Player.hpp"

#include <print>

class Potion : public Item {
public:
	Potion(const std::string& name, const std::string& description, float percent)
		: Item(name, description, ItemType::Potion), amount(1U), percent(percent) {}

	uint8_t GetAmount() const { return amount; }
	float GetPercent() const { return percent * 100; }
	void AddPotion() { ++amount; }
	void RemovePotion() { amount = std::max<uint8_t>(0, --amount); }
	std::string GetTypeString() const override { return "Potion"; }

	virtual void Use(Player& player) = 0;
	
	/* TEMPORARY FUNCTION FOR DEBUGGING -- DELETE */
	void PrintPotionInfo() {
		std::println("Name: {}", name);
		std::println("Description: {}", description);
		std::println("Type String: {}", GetTypeString());
		std::println("Amount: {}", amount);
		std::println("Percent Restored: {}%\n", GetPercent());
	}

	virtual ~Potion() = default;
protected:
	uint8_t amount;
	float percent;
};