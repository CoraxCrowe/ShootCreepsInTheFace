#include <string>

#include "Enemy.h"
#include "Message.h"
#include "Lunze.h"

  
Lunze::Lunze() {
  this->name = "lunze";

  this->pickLine1 = "A " + name + " appears, hasty on its four paws.";
  this->pickLine2 = "And it is light, and dressed in spotted fur.";
  this->pickLine3 = "And tries to impede your way without a pause.";

  this->victoryLine1 = "The bolts of me cut through the " + name + "'s hide.";
  this->victoryLine2 = "Like lightning parting clouds on its way down.";
  this->victoryLine3 = "And stopped the dance of living gears inside.";
  
  this->defeatLine1 = "I could not find a way to match its haste.";
  this->defeatLine2 = "And so defeated, I attend my fate.";
  this->defeatLine3 = "Bested by the last beast I'll ever face...";
  
  this->maxhp = 10;
  this->hp = 10;
  this->atk = 5;
  }
  

