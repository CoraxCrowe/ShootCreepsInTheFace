#ifndef __CORAX_ENEMY_H_
#define __CORAX_ENEMY_H_

#include <string>
#include "Character.h"

namespace Corax {

  class Enemy {
    public:
      std::string name = "monster";
      int hp = 10;
      int atk = 0;
      int atkType = 0;
      
      Enemy();
      Enemy(std::string name, int hp, int atk, int atkType);
      void inflictDamage(Corax::Character character, Corax::Message message);
      void takeDamage(int damage, int hp);
  };

}

#endif