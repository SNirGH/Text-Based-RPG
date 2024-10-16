#pragma once

#include "Weapon.hpp"1

class Dagger final : public Weapon {
public:
	Dagger(const std::string& name, const std::string& description, uint8_t baseDamage, Effects effect) 
		: Weapon(name, description, baseDamage, effect, WeaponType::Dagger) {}
};