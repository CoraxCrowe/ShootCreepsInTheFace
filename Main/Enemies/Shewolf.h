#ifndef __CORAX_SHEWOLF_H_
#define __CORAX_SHEWOLF_H_

#include <string>

#include "Enemy.h"
#include "Message.h"

class Shewolf : public Corax::Enemy {

  public:
    std::string name = "she-wolf";
    
    std::string pickLine1 = "A " + name + " appears, filled with craves.";
    std::string pickLine2 = "Or so she appears, meagre as she looks.";
    std::string pickLine3 = "And many people sent she to their graves.";

    std::string victoryLine1 = "O fangs who devour man, o twisted foe.";
    std::string victoryLine2 = "Go back from whence thee came in darkness hot.";
    std::string victoryLine3 = "And never dare you impede my journey more.";

    std::string defeatLine1 = "But in the end the she-wolf got the better";
    std::string defeatLine2 = "Of me, and wounded me to sure defeat.";
    std::string defeatLine3 = "So unfortunate have I been to have met her...";

    int maxhp = 10;
    int hp = 10;
    int atk = 5;

    int performAttack(Corax::Message message) {
      int dmg = int(atk * (rand() % 4 + 8)/10);

      hp += dmg/5;

      message.line1 = "The " + name + " attacks!";
      message.line2 = "Bites for a total of " + std::to_string(dmg) + " damage!";
      message.line3 = "Recovers " + std::to_string(dmg/5) + " health from your flesh.";
      

      return dmg;
    }

    
};

Shewolf shewolf;

#endif