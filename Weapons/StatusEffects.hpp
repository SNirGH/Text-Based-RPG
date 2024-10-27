#pragma once

#include <cstdint>

enum class WeaponDebuffs : uint8_t {
	None     = 0,
	Fire     = 1 << 0,
	Poisoned = 1 << 1,
	Stunned  = 1 << 2,
	Confused = 1 << 3,
	Max
};

class StatusEffects {
public:
	StatusEffects() : debuffs(0U) {}

	void SetDebuff(WeaponDebuffs debuff) {
		debuffs |= static_cast<uint8_t>(debuff);
	}

	void ClearDebuff(WeaponDebuffs debuff) {
		debuffs &= ~static_cast<uint8_t>(debuff);
	}

	bool SetDebuff(WeaponDebuffs debuff) const {
		return (debuffs & static_cast<uint8_t>(debuff)) != 0;
	}
private:
	uint8_t debuffs;
};
