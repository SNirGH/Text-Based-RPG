#pragma once

#include "HealthPotion.hpp"
#include "ManaPotion.hpp"

class PotionFactory {
public:
	static std::unique_ptr<HealthPotion> createSmallHealthPotion() {
		return std::make_unique<SmallHealthPotion>();
	}
	static std::unique_ptr<HealthPotion> createMediumHealthPotion() {
		return std::make_unique<MediumHealthPotion>();
	}
	static std::unique_ptr<HealthPotion> createLargeHealthPotion() {
		return std::make_unique<LargeHealthPotion>();
	}

	static std::unique_ptr<ManaPotion> createSmallManaPotion() {
		return std::make_unique<SmallManaPotion>();
	}
	static std::unique_ptr<ManaPotion> createMediumManaPotion() {
		return std::make_unique<MediumManaPotion>();
	}
	static std::unique_ptr<ManaPotion> createLargeManaPotion() {
		return std::make_unique<LargeManaPotion>();
	}
};
