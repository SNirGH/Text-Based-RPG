#pragma once

#include "StatusEffects.hpp"
#include "Weapon.hpp"
#include <cstdint>

class WeaponFactory {
public:
  class WeaponBuilder {
  public:
    WeaponBuilder &setName(const std::string &name) {
      this->name = name;
      return *this;
    }
    WeaponBuilder &setDescription(const std::string &description) {
      this->description = description;
      return *this;
    }
    WeaponBuilder &setBaseDamage(uint16_t baseDamage) {
      this->baseDamage = baseDamage;
      return *this;
    }
    WeaponBuilder &setWeaponDebuff(WeaponDebuffs debuff) {
      this->debuff = debuff;
      return *this;
    }
    WeaponBuilder &setWeaponType(WeaponType weaponType) {
      this->weaponType = weaponType;
      return *this;
    }
    std::unique_ptr<Weapon> build() {
      return std::make_unique<Weapon>(name, description, baseDamage, debuff, weaponType);
    }

  private:
    std::string name, description;
    uint16_t baseDamage;
    WeaponDebuffs debuff;
    WeaponType weaponType;
  };

  static WeaponBuilder createDaggerBuilder() {
    return WeaponBuilder().setWeaponType(WeaponType::Dagger);
  }
  static WeaponBuilder createSwordBuilder() {
    return WeaponBuilder().setWeaponType(WeaponType::Sword);
  }
  static WeaponBuilder createStaffBuilder() {
    return WeaponBuilder().setWeaponType(WeaponType::Staff);
  }
};
