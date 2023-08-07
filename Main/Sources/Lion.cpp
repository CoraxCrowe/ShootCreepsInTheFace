#include <string>

#include "Enemy.h"
#include "Message.h"
#include "Lion.h"


Lion::Lion() {
  this->name = "lion";

  this->pickLine1 = "O lord a " + name + " comes, with his head standing tall.";
  this->pickLine2 = "And angry hunger, making the air tremble.";
  this->pickLine3 = "And slowing my cautios journey to a crawl. ";

  this->victoryLine1 = "And yet the fiercest beast is slain by steel.";
  this->victoryLine2 = "Nor do the wounds they have inflicted soothe.";
  this->victoryLine3 = "But they glow red and bleed and pain me still.";

  this->defeatLine1 = "No reason could defeat the fiery beast.";
  this->defeatLine2 = "Nor could my weapons make quick work of him.";
  this->defeatLine3 = "But he triumphed, and made me his bloodied feast...";
  
  this->maxhp = 10;
  this->hp = 10;
  this->atk = 5;
  this->counter = 0;
}
  
