#pragma once

#include <algorithm>
#include <map>
#include <vector>

#include "Item.hpp"

class Inventory {
public:
  void AddItemToInventory(std::unique_ptr<Item> item) {
    uint8_t newId;
    if (!available_numbers.empty()) {
      std::sort(available_numbers.begin(), available_numbers.end());
      uint8_t available = available_numbers[0];
      newId = available;
      available_numbers.erase(available_numbers.begin());
    } else {
      newId = getNextId();
    }
    if (items.find(newId) == items.end())
      items[newId] = std::move(item);
  }

  void RemoveItemFromInventory(uint8_t id) {
    /* WILL NEED TO IMPLEMENT CHECK TO MAKE SURE PLAYER ENTERED VALID ID WHEN
     * ASKED */
    if (items.find(id) == items.end()) {
      std::println("\033[31mYou are trying to remove an Item that does not "
                   "exist.\033[0m");
      return;
    }
    items.erase(id);
    available_numbers.push_back(id);
  }

  void displayInventory() const {
    if (items.empty()) {
      std::println("Empty");
      return;
    }
    for (const auto &[id, item] : items) {
      std::print("Item ID: {} | ", id);
      std::print("Item Name: {} \t\t| ", item->GetName());
      std::println("Item Description: {}", item->GetDescription());
    }
  }

private:
  std::map<uint8_t, std::unique_ptr<Item>> items;
  std::vector<uint8_t> available_numbers;
  static uint8_t getNextId() { return currentId++; }
  static uint8_t currentId;
};

uint8_t Inventory::currentId = 1U;
