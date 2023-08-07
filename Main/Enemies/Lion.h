#ifndef __CORAX_LION_H_
#define __CORAX_LION_H_

#include <string>

#include "Enemy.h"
#include "Message.h"

class Lion : public Corax::Enemy {

  public:
    
    int counter = 0;
    Lion();

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

//Lion lion;

#endif