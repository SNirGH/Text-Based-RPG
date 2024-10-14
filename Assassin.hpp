#pragma once

#include "Player.hpp"

enum class AssassinMoveset : uint8_t {
	SneakAttack,
	Stun
};

class Assassin : public Player {
public:
	Assassin() : Player(15, 5, 0, 1, Type::Assassin) {}

	void printDescription() const override {
		std::println("This is a assassin.");
	}
};