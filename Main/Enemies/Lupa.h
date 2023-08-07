#include <string>

#include "Enemy.h"
#include "Message.h"

class Lupa : public Corax::Enemy {

  public:

    std::string name = "she-wolf";
    int hp = 10;
    int atk = 5;

    int performAttack(Corax::Message message) {
      int dmg = atk * (rand() % 4 + 8)/10;

      hp += dmg/5;

      message.line1 = "The " + name + " attacks!";
      message.line2 = "Bites for a total of " + std::to_string(dmg) + " damage!";
      message.line3 = "Recovers " + std::to_string(dmg/5) + " health from your flesh.";

      return dmg;
    }
};

Lupa lupa;