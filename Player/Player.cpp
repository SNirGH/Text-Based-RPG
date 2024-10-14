#include "Player.hpp"

std::string Player::getType() const {
	switch (type) {
	case Type::Assassin:
		return "Assassin";
	case Type::Mage:
		return "Mage";
	case Type::Warrior:
		return "Warrior";
	}
}