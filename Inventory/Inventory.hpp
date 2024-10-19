#pragma once

#include <unordered_map>

#include "../Potions/Potion.hpp"

class Inventory {
public: 
	void addToInventory(std::unique_ptr<Item> item) {
		items[item->getName()] = std::move(item);
	}

	bool findItemInInventory(const std::string& itemName) {
		return items.find(itemName) != items.end();
	}

	std::unique_ptr<Item>& getItem(const std::string& itemName) {
		return items.find(itemName)->second;
	}

	void removeFromInventory(const std::string& itemName) {
		auto item = items.find(itemName);

		if (item != items.end() and item->second)
			items.erase(item);
	}


    void listItems() const {
		std::println("-- Inventory --");
		std::println("Potions:");
		for (const auto& item : items) {
			if (item.second->getItemType() == ItemType::Potion) {
				Potion* potion = dynamic_cast<Potion*>(item.second.get());
				std::println("{} x {}", potion->getName(), potion->getAmount());
			}
		}

		std::println("\nWeapons:");
		for (const auto& item : items) {
			if (item.second->getItemType() == ItemType::Weapon) {
				std::println("{}", item.second->getName());
			}
		}
    }
private:
	std::unordered_map<std::string, std::unique_ptr<Item>> items;
};