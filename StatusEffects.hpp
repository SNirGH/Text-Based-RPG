#pragma once

#include <cstdint>
#include <print>

enum class Effects : uint8_t {
	None     = 0,
	Fire     = 1 << 0,
	Poisoned = 1 << 1,
	Stunned  = 1 << 2,
	Frozen   = 1 << 3
};

class StatusEffects {
public:
	// Initialize StatusEffects to None
	StatusEffects() : debuffs(0U) {}

	// Set a debuff from the Effects struct
	void setDebuff(Effects effect) {
		debuffs |= static_cast<uint8_t>(effect);
	}

	// Clear a specific debuff
	void clearDebuff(Effects effect) {
		debuffs &= ~static_cast<uint8_t>(effect);
	}

	// Check to see if player has a debuff
	bool hasDebuff(Effects effect) const {
		return (debuffs & static_cast<uint8_t>(effect)) != 0;
	}
private:
	uint8_t debuffs;
};