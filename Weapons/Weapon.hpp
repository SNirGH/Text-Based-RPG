#pragma once

#include "../Inventory/Item.hpp"
#include "StatusEffects.hpp"

enum class WeaponType : uint8_t { Dagger, Staff, Sword };

class Weapon : public Item {
public:
  Weapon(const std::string &name, const std::string &description,
         uint16_t baseDamage, WeaponDebuffs debuff, WeaponType weaponType)
      : Item(name, description, ItemType::Weapon), baseDamage(baseDamage),
        debuff(debuff), weaponType(weaponType) {}

  std::string GetTypeString() const override { return "Weapon"; }

  void printBaseDamage() { std::println("Base Weapon Damage: {}", baseDamage); }
  void printWeaponDebuff() {
    std::print("Weapon Debuff: ");
    switch (debuff) {
    case WeaponDebuffs::Stunned:
      std::println("Stunned");
      break;
    case WeaponDebuffs::Fire:
      std::println("Fire");
      break;
    case WeaponDebuffs::Confused:
      std::println("Confused");
      break;
    case WeaponDebuffs::Poisoned:
      std::println("Poison");
      break;
    default:
      std::println("None");
      break;
    }
  }

  void printWeaponType() {
    std::print("Weapon Type: ");
    switch (weaponType) {
    case WeaponType::Dagger:
      std::println("Dagger");
      break;
    case WeaponType::Staff:
      std::println("Staff");
      break;
    case WeaponType::Sword:
      std::println("Sword");
      break;
    }
  }

  void printStats() override {
    printName();
    printDescription();
    printBaseDamage();
    printWeaponDebuff();
    printWeaponType();
    std::println("\n");
  }

  virtual ~Weapon() = default;

protected:
  uint16_t baseDamage;
  WeaponDebuffs debuff;
  WeaponType weaponType;
};
