#include <cctype>
#include <iostream>
#include <random>
#include <vector>

#include "../Inventory/Item.hpp"
#include "../Potions/PotionFactory.hpp"
#include "../Weapons/WeaponFactory.hpp"

class Chest {
public:
  Chest() {
    chestItems.emplace_back(PotionFactory::createSmallHealthPotion());
    chestItems.emplace_back(PotionFactory::createMediumHealthPotion());
    chestItems.emplace_back(PotionFactory::createLargeHealthPotion());
    chestItems.emplace_back(PotionFactory::createSmallManaPotion());
    chestItems.emplace_back(PotionFactory::createMediumManaPotion());
    chestItems.emplace_back(PotionFactory::createLargeManaPotion());
    chestItems.emplace_back(
        WeaponFactory::createSwordBuilder()
            .setName("Excalibur")
            .setDescription("The legendary sword wielded by King Arthur.")
            .setBaseDamage(100)
            .setWeaponDebuff(WeaponDebuffs::Stunned)
            .build());
    chestItems.emplace_back(
        WeaponFactory::createStaffBuilder()
            .setName("Elder Staff")
            .setDescription(
                "A staff said to have been created by Death himself.")
            .setBaseDamage(100)
            .setWeaponDebuff(WeaponDebuffs::Fire)
            .build());
    chestItems.emplace_back(
        WeaponFactory::createDaggerBuilder()
            .setName("Poison Dagger")
            .setDescription(
                "A dagger so poisonous, one scratch could kill you.")
            .setBaseDamage(75)
            .setWeaponDebuff(WeaponDebuffs::Poisoned)
            .build());
    chestItems.emplace_back(
        WeaponFactory::createSwordBuilder()
            .setName("Gram")
            .setDescription(
                "The sword used by Sigurd to slay the dragon Fafnir.")
            .setBaseDamage(100)
            .setWeaponDebuff(WeaponDebuffs::Fire)
            .build());
  }

  bool ConfirmOpen() {
    char choice;
    do {
      std::print("Would you like to open the chest? (y/n): ");
      std::cin >> choice;
      choice = std::tolower(choice);

      if (choice != 'y' and choice != 'n')
        std::println("\033[31mInvalid Choice. Please enter 'y' or 'n'.\033[0m");
    } while (choice != 'y' and choice != 'n');

    return choice == 'y';
  }
  bool isEmpty() { return chestItems.empty(); }

  std::unique_ptr<Item> Open() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> dis(0, chestItems.size() - 1);

    uint8_t index = dis(gen);

    std::unique_ptr<Item> selectItem = std::move(chestItems[index]);
    chestItems.erase(chestItems.begin() + index);

    selectItem->printStats();
    std::println("Recieved: {}", selectItem->GetName());

    return selectItem;
  }

private:
  std::vector<std::unique_ptr<Item>> chestItems;
};
