#pragma once

#include "Dagger.hpp"
#include "Sword.hpp"
#include "Staff.hpp"

class WeaponFactory {
public:
	static std::unique_ptr<Weapon> createDagger(const std::string& name, const std::string& description, WeaponDebuffs debuff) {
		return std::make_unique<Dagger>(name, description,  debuff);
	}
	static std::unique_ptr<Weapon> createSword(const std::string& name, const std::string& description, WeaponDebuffs debuff) {
		return std::make_unique<Sword>(name, description, debuff);
	}
	static std::unique_ptr<Weapon> createStaff(const std::string& name, const std::string& description, WeaponDebuffs debuff) {
		return std::make_unique<Staff>(name, description, debuff);
	}
};