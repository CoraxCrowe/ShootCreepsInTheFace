#include <string>

#include "Enemy.h"
#include "Message.h"

class Leone : public Corax::Enemy {

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
      temp = atk*3 * (rand() % 4 + 8)/10;
      counter = 0;

      message.line1 = "The " + name + " prowls with might.";
      message.line2 = "It slams you with all its strength.";
      message.line3 = "It pounds you for " + std::to_string(temp) + " damage.";
    }
    return temp;
  }


};

Leone leone;