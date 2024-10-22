#pragma once

#include <map>
#include <vector>
#include <algorithm>

#include "Item.hpp"

//struct CompositeKey {
//	uint8_t id;
//	ItemType itemType;
//
//	bool operator==(const CompositeKey& other) const {
//		return id == other.id and itemType == other.itemType;
//	}
//};
//
//struct KeyHasher {
//	std::size_t operator()(const CompositeKey& k) const {
//		return std::hash<uint8_t>()(k.id) ^ std::hash<ItemType>()(k.itemType);
//	}
//};

class Inventory {
public:
	void AddItemToInventory(std::unique_ptr<Item> item) {
		uint8_t newId;
		if (!available_numbers.empty()) {
			std::sort(available_numbers.begin(), available_numbers.end());
			uint8_t available = available_numbers[0];
			newId = available;
			available_numbers.erase(available_numbers.begin());
		}
		else {
			newId = getNextId();
		}
		if (items.find(newId) == items.end())
			items[newId] = std::move(item);
	}

	void RemoveItemFromInventory(uint8_t id) {
		available_numbers.push_back(id);
		items.erase(id);
	}

	void displayInventory() const {
		for (const auto& [id, item] : items) {
			std::cout << "Item ID: " << static_cast<int>(id) << " - ";
			std::cout << "Item Name: " << item->GetName() << " - ";
			std::cout << "Item Description: " << item->GetDescription() << std::endl;
		}
	}

private:
	std::map<uint8_t, std::unique_ptr<Item>> items;
	std::vector<uint8_t> available_numbers;
	static uint8_t getNextId() {
		return currentId++;
	}
	static uint8_t currentId;
};

uint8_t Inventory::currentId = 1U;