#ifndef __CORAX_LION_H_
#define __CORAX_LION_H_

#include <string>

#include "Enemy.h"
#include "Message.h"

class Lion : public Corax::Enemy {

  public:
    std::string name = "lion";

    std::string pickLine1 = "O lord a " + name + " comes, with his head standing tall.";
    std::string pickLine2 = "And angry hunger, making the air tremble.";
    std::string pickLine3 = "And slowing my cautios journey to a crawl. ";

    std::string victoryLine1 = "And yet the fiercest beast is slain by steel.";
    std::string victoryLine2 = "Nor do the wounds they have inflicted soothe.";
    std::string victoryLine3 = "But they glow red and bleed and pain me still.";

    std::string defeatLine1 = "No reason could defeat the fiery beast.";
    std::string defeatLine2 = "Nor could my weapons make quick work of him.";
    std::string defeatLine3 = "But he triumphed, and made me his bloodied feast...";
    
    int maxhp = 10;
    int hp = 10;
    int atk = 5;
    int counter = 0;
    

    int performAttack(Corax::Message message) {
      counter ++;
      int temp = 0;

      message.line1 = "The " + name + " roars!";
      message.line2 = "It charges an attack...";
      message.line3 = "It stares at you with a hideous grin.";

      if (counter > 1) {
        temp = int(atk*3 * (rand() % 4 + 8)/10);
        counter = 0;

        message.line1 = "The " + name + " prowls with might.";
        message.line2 = "It slams you with all its strength.";
        message.line3 = "It pounds you for " + std::to_string(temp) + " damage.";
    }
    return temp;
  }


};

Lion lion;

#endif