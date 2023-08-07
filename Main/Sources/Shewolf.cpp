#include <string>

#include "Enemy.h"
#include "Message.h"
#include "Shewolf.h"

Shewolf::Shewolf() {
  this->name = "she-wolf";
  
  this->pickLine1 = "A " + name + " appears, filled with craves.";
  this->pickLine2 = "Or so she appears, meagre as she looks.";
  this->pickLine3 = "And many people sent she to their graves.";

  this->victoryLine1 = "O fangs who devour man, o twisted foe.";
  this->victoryLine2 = "Go back from whence thee came in darkness hot.";
  this->victoryLine3 = "And never dare you impede my journey more.";

  this->defeatLine1 = "But in the end the she-wolf got the better";
  this->defeatLine2 = "Of me, and wounded me to sure defeat.";
  this->defeatLine3 = "So unfortunate have I been to have met her...";

  this->maxhp = 10;
  this->hp = 10;
  this->atk = 5;

}

