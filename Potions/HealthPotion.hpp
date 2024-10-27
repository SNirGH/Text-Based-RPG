#pragma once

#include "Potion.hpp"

class HealthPotion : public Potion {
public:
	HealthPotion(const std::string& name, const std::string& description, float percent)
		: Potion(name, description, percent) {}

	void Use(Player& player) override {
		if (amount == 0) return;

		player.RestoreHealth(percent);
		RemovePotion();
	}

	virtual ~HealthPotion() = default;
};

class SmallHealthPotion : public HealthPotion {
public:
	SmallHealthPotion()
		: HealthPotion("Small Health Potion", "Restores a small amount of health.", 0.25F) {}
};

class MediumHealthPotion : public HealthPotion {
public:
	MediumHealthPotion()
		: HealthPotion("Medium Health Potion", "Restores a medium amount of health.", 0.50F) {}
};

class LargeHealthPotion : public HealthPotion {
public:
	LargeHealthPotion()
		: HealthPotion("Large Health Potion", "Restores a large amount of health.", 0.75F) {}
};