#pragma once

#include "Potion.hpp"

class ManaPotion : public Potion {
public:
	ManaPotion(const std::string& name, const std::string& description, float percent)
		: Potion(name, description, percent) {}

	void Use(Player& player) override {
		if (amount == 0) return;

		player.RestoreMana(percent);
		RemovePotion();
	}

	virtual ~ManaPotion() = default;
};

class SmallManaPotion : public ManaPotion {
public:
	SmallManaPotion()
		: ManaPotion("Small Mana Potion", "Restores a small amount of mana.", 0.25F) {}
};

class MediumManaPotion : public ManaPotion {
public:
	MediumManaPotion()
		: ManaPotion("Medium Mana Potion", "Restores a medium amount of mana.", 0.50F) {}
};

class LargeManaPotion : public ManaPotion {
public:
	LargeManaPotion()
		: ManaPotion("Large Mana Potion", "Restores a large amount of mana.", 0.75F) {}
};