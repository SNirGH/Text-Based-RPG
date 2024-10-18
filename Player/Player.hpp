#pragma once

#include <memory>

#include "../Inventory/Inventory.hpp"
#include "../Status Effects/StatusEffects.hpp"

enum class PlayerType : uint8_t { Assassin, Mage, Warrior };

class Player {
public:
	Player(uint8_t hp, uint8_t mp, uint8_t xp, uint8_t level, PlayerType type)
		: currentHP(hp), maxHP(hp), currentMP(mp), maxMP(mp),
		  currentXP(xp), maxXP(100), level(level), type(type) {}

	virtual void printDescription() const = 0;

	uint8_t getHealth() const { return currentHP; }
	float getMana() const { return currentMP; }
	uint8_t getLevel() const { return level; }
	void LevelUp() { ++level; }

	std::string getType() const;

	void printStats() const {
		std::println("\nPlayer is a: {}", getType());
		std::println("Health: {}/{}", currentHP, maxHP);
		std::println("Mana: {}", currentMP);
		std::println("XP: {}", currentXP);
		std::println("Level: {}", level);
	}

	void addItemToInventory(std::unique_ptr<Item> item) {
		inventory->addToInventory(std::move(item));
	}

	bool findItemInInventory(const std::string& itemName) {
		return inventory->findItemInInventory(itemName);
	}

	void removeItemFromInventory(const std::string& itemName) {
		inventory->removeFromInventory(itemName);
	}

	void listItemsInInventory() const {
		inventory->listItems();
	}

	template<class T>
		requires std::is_arithmetic<T>::value
	void Restore(float percent, T& current, T max) {
		current = std::min<T>(current + (max * percent), max);
	}
	void RestoreHealth(float percent) {
		Restore(percent, currentHP, maxHP);
	}
	void RestoreMana(float percent) {
		Restore(percent, currentMP, maxMP);
	}

	void TakeDamage(uint8_t amount) {
		currentHP = (currentHP >= amount) ? (currentHP - amount) : 0;
	}

	void ConsumeMana(uint8_t amount) {
		currentMP = (currentMP >= amount) ? (currentMP - amount) : 0;
	}

	virtual ~Player() = default;

protected:
	uint8_t currentHP, maxHP, currentXP, maxXP, level;
	float currentMP, maxMP;
	PlayerType type;

	std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>();
	std::unique_ptr<StatusEffects> debuffs = std::make_unique<StatusEffects>();
};