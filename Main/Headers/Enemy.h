#ifndef __CORAX_ENEMY_H_
#define __CORAX_ENEMY_H_

#include <string>
#include "Character.h"
#include "Message.h"

namespace Corax {

  class Enemy {
    public:
      std::string name = "monster";

      int maxhp = 10;
      int hp = 10;
      int atk = 0;
      int numberOfEnemiesEncountered;

      std::string pickLine1 = "";
      std::string pickLine2 = "";
      std::string pickLine3 = "";

      std::string victoryLine1 = "";
      std::string victoryLine2 = "";
      std::string victoryLine3 = "";

      std::string defeatLine1 = "";
      std::string defeatLine2 = "";
      std::string defeatLine3 = "";
     
      Enemy();
      Enemy(std::string name, int hp, int atk);
      
      int performAttack(Corax::Message message);
  };

}

#endif