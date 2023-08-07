#ifndef __CORAX_LUNZE_H_
#define __CORAX_LUNZE_H_

#include <string>

#include "Enemy.h"
#include "Message.h"

class Lunze : public Corax::Enemy {

  public:
    std::string name = "lunze";

    std::string pickLine1 = "A " + name + " appears, hasty on its four paws.";
    std::string pickLine2 = "And it is light, and dressed in spotted fur.";
    std::string pickLine3 = "And tries to impede your way without a pause.";

    std::string victoryLine1 = "The bolts of me cut through the " + name + "'s hide.";
    std::string victoryLine2 = "Like lightning parting clouds on its way down.";
    std::string victoryLine3 = "And stopped the dance of living gears inside.";

    std::string defeatLine1 = "I could not find a way to match its haste.";
    std::string defeatLine2 = "And so defeated, I attend my fate.";
    std::string defeatLine3 = "Bested by the last beast I'll ever face...";
    
    int maxhp = 10;
    int hp = 10;
    int atk = 5;
    
    int performAttack(Corax::Message message) {
      int temp = 0;
      int dmg = 0;
      
      for (int i = 0; i < 3; i++) {
        if (rand() % 2 == 1) {
          dmg += int(atk*0.5 * (rand() % 4 + 8)/10);
          temp += 1;
        }
      }

      message.line1 = "The " + name + " attacks!";
      message.line2 = "Hits " + std::to_string(temp) + " times";
      message.line3 = "Hits for a total of " + std::to_string(dmg) + " damage!";

      return dmg;
  }
};

Lunze lunze;

#endif