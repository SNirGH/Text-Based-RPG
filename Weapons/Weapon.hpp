#pragma once

#include "../Inventory/Item.hpp"
#include "StatusEffects.hpp"

enum class WeaponType : uint8_t { Dagger, Staff, Sword };

class Weapon : public Item {
public:
	Weapon(const std::string& name, const std::string& description, WeaponType weaponType)
		: Item(name, description, ItemType::Weapon), weaponType(weaponType) {}

	std::string GetTypeString() const override { return "Weapon"; }

	virtual std::string GetWeaponTypeString() const = 0;

	/* TEMPORARY FUNCTION FOR DEBUGGING -- DELETE */
	void PrintWeaponInfo() {
		std::println("Name: {}", name);
		std::println("Description: {}", description);
		std::println("Item Type String: {}", GetTypeString());
		std::println("Weapon Type String: {}", GetWeaponTypeString());
	}

	virtual ~Weapon() = default;
protected:
	WeaponType weaponType;
};