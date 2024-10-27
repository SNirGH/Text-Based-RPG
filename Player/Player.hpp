#pragma once

#include "../Potions/Potion.hpp"
#include "../Inventory/Inventory.hpp"

enum class PlayerType : uint8_t { Assassin, Mage, Warrior };

class Player {
public:
	Player(uint16_t currentHP, uint16_t currentMP, PlayerType playerType)
		: currentHP(currentHP), maxHP(currentHP), currentMP(currentMP), maxMP(currentMP),
		currentXP(0U), maxXP(100U), level(1U), playerType(playerType) {}

	uint16_t GetHealth() const { return currentHP; }
	uint16_t GetMana() const { return currentMP; }
	uint16_t GetXP() const { return currentXP; }
	uint8_t GetLevel() const { return level; }
	PlayerType GetPlayerType() const { return playerType; }

	void GainXP(uint16_t amount) {
		currentXP += amount;
		while (currentXP >= maxXP)
			LevelUp();
	}

	void LevelUp() {
		++level;

		maxHP = maxHP + 100U;
		currentHP = maxHP;
		maxMP = maxMP + 100U;
		currentMP = maxMP;

		currentXP = currentXP - maxXP;
		maxXP += 100U;
	}

	void Restore(float percent, uint16_t current, uint16_t max) {
		current = std::min<uint16_t>(current + (max * percent), max);
	}
	void RestoreHealth(float percent) {
		Restore(percent, currentHP, maxHP);
	}
	void RestoreMana(float percent) {
		Restore(percent, currentMP, maxMP);
	}

	void AddItemToInventory(std::unique_ptr<Item> item) {
		inventory->AddItemToInventory(std::move(item));
	}

	void RemoveItemFromInventory(uint8_t id) {
		inventory->RemoveItemFromInventory(id);
	}

	void displayInventory() {
		inventory->displayInventory();
	}

	void TakeDamage(uint16_t amount) {
		currentHP = (currentHP >= amount) ? (currentHP - amount) : 0;
	}

	void ConsumeMana(uint16_t amount) {
		currentMP = (currentMP >= amount) ? (currentMP - amount) : 0;
	}

	void printStats() const {
		std::println("\nPlayer is a: {}", (uint8_t)GetPlayerType());
		std::println("Health: {}/{}", currentHP, maxHP);
		std::println("Mana: {}/{}", currentMP, maxMP);
		std::println("XP: {}/{}", currentXP, maxXP);
		std::println("Level: {}", level);
	}

	virtual ~Player() = default;
protected:
	uint16_t currentHP, maxHP, currentMP, maxMP, currentXP, maxXP;
	uint8_t level;
	PlayerType playerType;
	std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>();
};
