#pragma once

#include <memory>
#include "../Status Effects/StatusEffects.hpp"

enum class PlayerType : uint8_t { Assassin, Mage, Warrior };

class Player {
public:
	Player(uint8_t hp, uint8_t mp, uint8_t xp, uint8_t level, PlayerType type)
		: currentHP(hp), maxHP(hp), currentMP(mp), maxMP(mp),
		  currentXP(xp), maxXP(100), level(level), type(type) {}

	virtual void printDescription() const = 0;

	uint8_t getHealth() const { return currentHP; }
	void setHealth(int hp) { currentHP = hp; }

	uint8_t getMana() const { return currentMP; }
	void setMana(int mp) { currentMP = mp; }
	
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
protected:
	uint8_t currentHP, maxHP, currentMP, maxMP, currentXP, maxXP, level;
	const PlayerType type;
	std::unique_ptr<StatusEffects> debuffs = std::make_unique<StatusEffects>();
};