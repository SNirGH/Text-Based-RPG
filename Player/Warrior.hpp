#pragma once

#include "Player.hpp"

class Warrior : public Player {
public:
	Warrior () : Player(20, 0, 0, 1, PlayerType::Warrior) {}

	void printDescription() const override {
		std::println("This is the warrior class");
	}
};