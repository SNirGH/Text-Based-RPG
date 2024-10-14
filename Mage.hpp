#pragma once

#include "Player.hpp"

class Mage final : public Player {
public:
	Mage() : Player(10, 10, 0, 1, Type::Mage) {}

	void printDescription() const override {
		std::println("This is a mage.");
	}
};