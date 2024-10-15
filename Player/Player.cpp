#include "Player.hpp"

std::string Player::getType() const {
	switch (type) {
	case PlayerType::Assassin:
		return "Assassin";
	case PlayerType::Mage:
		return "Mage";
	case PlayerType::Warrior:
		return "Warrior";
	default:
		return "Error";
	}
}