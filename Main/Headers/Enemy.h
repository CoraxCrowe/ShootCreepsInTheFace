#ifndef __CORAX_ENEMY_H_
#define __CORAX_ENEMY_H_

#include <string>
#include "Character.h"
#include "message.h"

namespace Corax {

  class Enemy {
    public:
      std::string name = "monster";
      int hp = 10;
      int atk = 0;
      
      Enemy();
      Enemy(std::string name, int hp, int atk, int atkType);
      
      void performAttack();
  };

}

#endif