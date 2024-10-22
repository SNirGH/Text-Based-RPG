#pragma once

#include "Weapon.hpp"

class Dagger : public Weapon {
public:
	Dagger(const std::string& name, const std::string& description, WeaponDebuffs debuff)
		: Weapon(name, description, WeaponType::Dagger), debuff(debuff) {}

	std::string GetWeaponTypeString() const override { return "Dagger"; }
private:
	WeaponDebuffs debuff;
};