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

	uint8_t getLevel() const { return level; }
	void setLevel(int lvl) { level = lvl; }

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

	void listItemsInInventory() const {
		inventory->listItems();
	}

	void Restore(float percent, uint8_t& current, uint8_t max) {
		current = std::min(static_cast<int>(current + (current * percent)), static_cast<int>(max));
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

protected:
	uint8_t currentHP, maxHP, currentMP, maxMP, currentXP, maxXP, level;
	PlayerType type;

	std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>();
	std::unique_ptr<StatusEffects> debuffs = std::make_unique<StatusEffects>();
};