#pragma once

#include "Player.hpp"

class Mage : public Player {
public:
	Mage(uint16_t currentHP, uint16_t currentMP)
		: Player(currentHP, currentMP, PlayerType::Mage) {}
};