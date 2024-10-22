#pragma once

#include "Weapon.hpp"

class Staff : public Weapon {
public:
	Staff(const std::string& name, const std::string& description, WeaponDebuffs debuff)
		: Weapon(name, description, WeaponType::Dagger), debuff(debuff) {}

	std::string GetWeaponTypeString() const override { return "Staff"; }
private:
	WeaponDebuffs debuff;
};