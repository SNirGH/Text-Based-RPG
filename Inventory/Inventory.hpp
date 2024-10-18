#pragma once

#include <unordered_map>
#include <vector>
#include <iostream>

#include "Item.hpp"

class Inventory {
public: 
	void addToInventory(std::unique_ptr<Item> item) {
		items[item->getName()] = std::move(item);
	}

	bool findItemInInventory(const std::string& itemName) {
		return items.find(itemName) != items.end();
	}

	void removeFromInventory(const std::string& itemName) {
		auto item = items.find(itemName);

		if (item != items.end() and item->second)
			items.erase(item);
	}

    void listItems() const {
        
    }
private:
	std::unordered_map<std::string, std::unique_ptr<Item>> items;
};