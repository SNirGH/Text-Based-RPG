#pragma once

#include <unordered_map>
#include <vector>

#include "Item.hpp"

class Inventory {
public: 
	void addToInventory(std::unique_ptr<Item> item) {
		items[item->getItemType()].emplace_back(std::move(item));
	}

	bool findItemInInventory(ItemType itemType, const std::string& itemName) {
		std::vector<std::unique_ptr<Item>>& itemList = items[itemType];
		
		for (const std::unique_ptr<Item>& item : itemList) {
			std::println("Checking item: {}", item->getName());
			if (item->getName() == itemName)
				return true;
		}

		return false;
	}

	void removeFromInventory(ItemType itemType, const std::string& itemName) {
		std::vector<std::unique_ptr<Item>>& itemList = items[itemType];

		std::vector<std::unique_ptr<Item>>::iterator it = std::remove_if(itemList.begin(), itemList.end(),
			[&itemName](const std::unique_ptr<Item>& item) {
				return item->getName() == itemName;
			});

		if (it != itemList.end()) {
			itemList.erase(it, itemList.end());
		}
	}

	void listItems() const {
		for (const auto& [itemType, itemList] : items) {
			std::println("{}", (itemType == ItemType::Weapon ? "Weapons:" : "Potions:"));
			for (const std::unique_ptr<Item>& item : itemList) {
				std::println(" * {}", item->getName());
			}
		}
	}
private:
	std::unordered_map<ItemType, std::vector<std::unique_ptr<Item>>> items;
};