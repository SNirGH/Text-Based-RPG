#include "Weapon.hpp"

class Sword : public Weapon {
public:
	Sword(const std::string& name, const std::string& description, WeaponDebuffs debuff)
		: Weapon(name, description, WeaponType::Sword), debuff(debuff) {}

	std::string GetWeaponTypeString() const override { return "Sword"; }
private:
	WeaponDebuffs debuff;
};