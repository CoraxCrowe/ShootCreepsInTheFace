#ifndef __CORAX_SHEWOLF_H_
#define __CORAX_SHEWOLF_H_

#include <string>

#include "Enemy.h"
#include "Message.h"

class Shewolf : public Corax::Enemy {

  public:

      Shewolf();
      
      int performAttack(Corax::Message message) {
      int dmg = int(atk * (rand() % 4 + 8)/10);

      hp += dmg/5;

      message.line1 = "The " + name + " attacks!";
      message.line2 = "Bites for a total of " + std::to_string(dmg) + " damage!";
      message.line3 = "Recovers " + std::to_string(dmg/5) + " health from your flesh.";
      

      return dmg;
    }

    
};

//Shewolf shewolf;

#endif