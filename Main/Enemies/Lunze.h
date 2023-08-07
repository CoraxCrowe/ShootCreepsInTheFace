#ifndef __CORAX_LUNZE_H_
#define __CORAX_LUNZE_H_

#include <string>

#include "Enemy.h"
#include "Message.h"

class Lunze : public Corax::Enemy {

  public:
    
    Lunze();
    
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



#endif