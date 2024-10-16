#pragma once

#include <string>

#include "../Inventory/Item.hpp"

enum class WeaponType {
	Dagger,
	Staff,
	Sword
};

class Weapon : public Item {
public:
	Weapon(const std::string& name, const std::string& description, uint8_t baseDamage, Effects debuff, WeaponType weaponType)
		: Item(name, description, ItemType::Weapon),
		  baseDamage(baseDamage), currentDamage(baseDamage), debuff(debuff), weaponType(weaponType) {}
	
	std::string GetWeaponType() {
		switch (this->weaponType) {
		case WeaponType::Dagger:
			return "Dagger";
		case WeaponType::Staff:
			return "Staff";
		case WeaponType::Sword:
			return "Sword";
		}
	}

	void printWeaponStats() {
		std::println("Name: {}", this->name);
		std::println("Description: {}", this->description);
		std::println("Base Damage: {}", this->baseDamage);
		std::println("Weapon Type: {}", this->GetWeaponType());
	}
	std::string GetWeaponDebuff(Effects debuff);
protected:
	uint8_t baseDamage, currentDamage;
	WeaponType weaponType;
	Effects debuff;
};