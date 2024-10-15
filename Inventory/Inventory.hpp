#pragma once

#include <unordered_map>
#include <vector>

#include "Item.hpp"

class Inventory {
public: 
	void addToInventory(ItemType itemType, std::unique_ptr<Item> item) {
		items[itemType].emplace_back(std::move(item));
	}

	void removeFromInventory(ItemType itemType, std::unique_ptr<Item> item) {
		std::vector<std::unique_ptr<Item>>& itemList = items[itemType];

		std::vector<std::unique_ptr<Item>>::iterator it = std::find(itemList.begin(), itemList.end(), item);

		if (it != itemList.end())
			itemList.erase(it);
	}

	void listItems() const {
		for (const auto& [itemType, itemList] : items) {
			std::println("{}", (itemType == ItemType::Weapon ? "Weapons:" : "Potions:"));
			for (const auto& item : itemList) {
				std::println(" - {}", item->getName());
			}
		}
	}
private:
	std::unordered_map<ItemType, std::vector<std::unique_ptr<Item>>> items;
};