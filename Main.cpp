#include <chrono>
#include <print>
#include <thread>

#include "Chest/Chest.hpp"
#include "Player/Player.hpp"
#include "Player/PlayerFactory.hpp"

void sleep_random_range(int min_ms, int max_ms) {
  static std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(min_ms, max_ms);
  int sleep_time = dist(rng);

  std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
}

void typewriter(const std::string &msg) {
  for (size_t i = 0; msg[i] != '\0'; i++) {
    if (msg[i] == ' ') {
      sleep_random_range(70, 200);
    } else {
      sleep_random_range(50, 100);
    }

    std::print("{}", msg[i]);
    fflush(stdout);
  }

  std::println();
}

int main() {
  /*char choice;

  std::unique_ptr<Player> player;

  do {
          std::print("Which class would you like: ");
          choice = _getch();

          switch (choice) {
          case '1':
                  player = std::make_unique<Assassin>();
                  break;
          case '2':
                  player = std::make_unique<Mage>();
                  break;
          case '3':
                  player = std::make_unique<Warrior>();
                  break;
          default:
                  std::println("\033[31mInvalid value\033[0m");
                  break;
          }
          player->printStats();
          player->printDescription();
          std::println("");
  } while ((choice < 49 or choice > 51) or choice != 'q');*/

  auto player = PlayerFactory::createMage();
  Chest chest;

  while (!chest.isEmpty())
    player->AddItemToInventory(chest.Open());

  std::println("The chest ran out of items.");
  player->displayInventory();

  std::println();
  player->printStats();
  player->GainXP(6750);
  player->printStats();
}
