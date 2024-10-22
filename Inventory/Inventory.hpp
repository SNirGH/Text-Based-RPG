#pragma once

#include <map>

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
			std::map<uint8_t, uint8_t>::iterator it = available_numbers.begin();
			newId = it->first;
			available_numbers.erase(it);
		}
		else {
			newId = getNextId();
		}
		if (items.find(newId) == items.end())
			items[newId] = std::move(item);
	}

	void RemoveItemFromInventory(uint8_t id) {
		available_numbers[id] = id;
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
	std::map<uint8_t, uint8_t> available_numbers;
	static uint8_t getNextId() {
		return currentId++;
	}
	static uint8_t currentId;
};

uint8_t Inventory::currentId = 1U;