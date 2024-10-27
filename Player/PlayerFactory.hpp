#pragma once

#include "Mage.hpp"

class PlayerFactory {
public:
	static std::unique_ptr<Player> createMage() {
		return std::make_unique<Mage>(100, 50);
	}
};