#include <iostream>
#include <ctime>
#include <string>

#include "Main.h"
#include "Character.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Message.h"



int main() {
  bool isRunning = true;
  Corax::Message message;
  Corax::Enemy currentEnemy;
  Corax::Character character;
  Corax::Weapon weapon;
  
  srand(time(NULL));

    gameStart(character, message);

    while(isRunning) {

    drawScreen(character, message);
        
    currentEnemy = pickEnemy(currentEnemy, message);
    
    drawScreen(character, message);

    startFight(character, currentEnemy, message);

  }


  return 0;
}

void drawBottomScreenUI(Corax::Message message) {
  
  message.updateLines(message.line1, message.line2,message.line3);
  std::cout << "_________________________________________________________________________________\n";
  std::cout << "||                                                                             ||\n";
  std::cout << "||" << message.line1 << "||\n";
  std::cout << "||" << message.line2 << "||\n";
  std::cout << "||" << message.line3 << "||\n";
  std::cout << "||                                                                             ||\n";
  std::cout << "||_____________________________________________________________________________||\n";              
}

void drawTopScreenUI(Corax::Character character) {
  char lifebar[] = "1234567890";

  for (int i = 0; i < (character.maxHp)/100; i++) {
    if (i < character.currentHp/100) {
      lifebar[i] = 'O';
    } else {
      lifebar[i] = '-';
    }
  }

  std::cout << "                      ||                                ||                      \n";
  std::cout << "        * x " << character.numberOfBombs << "         ||          [" << lifebar << "]          ||        knife  /      \n";
  std::cout << "______________________||________________________________||______________________\n";

}

void drawPortraits () {
  
  for (int i = 0; i < 12; i++) {
    std::cout << "                                                                                \n";
  }
  

}

Corax::Enemy pickEnemy(Corax::Enemy currentEnemy, Corax::Message message) {
  
  int enemyType;  

  enemyType = 0; //rand() % 5;

  switch (enemyType) {
    case 0: 
      currentEnemy.name = "lonza";
       //progressively gets stronger
      break;
    case 1: 
      currentEnemy.name = "Phantom"; //can be missed
      break;
    case 2: 
      currentEnemy.name = "Swarm of Bats"; //attacks 0-3 times
      break;
    case 3: 
      currentEnemy.name = "Slime"; //regens life on hit
      break;
    case 4:
      currentEnemy.name = "Snake"; //hits with strength 3x every third time 
      break;
  }
  
  return currentEnemy;
}

void startFight(Corax::Character character, Corax::Enemy currentEnemy, Corax::Message message) {
  
  while (character.currentHp > 0 && currentEnemy.hp > 0) {

    fightTurnPlayer(character, currentEnemy, message);

    if (currentEnemy.hp > 0) {
      
      fightTurnCurrentEnemy(character, currentEnemy, message);
    }

  }

  if (character.currentHp <= 0) {
    loseFight(message);
  } else {
    winFight(message);
  }
  

}

void fightTurnPlayer(Corax::Character character, Corax::Enemy currentEnemy, Corax::Message message) {
  
  int optionSelect;
  message.line1 = "Press 1 to attack and 2 to launch a bomb\n";
  message.line2 = "\n";
  message.line3 = "\n";

  std::cin >> optionSelect;

  if (optionSelect == 1) {
      currentEnemy.hp -= character.weapon.damage;
      character.weapon.ammo -= 1;
      message.line1 = "The warrior attacks\n";
      message.line2 = "Dealing " + std::to_string(character.weapon.damage) + " damage";
      
      if (currentEnemy.hp > 0) {
        message.line3 = "The foe prepares an attack.";
      } else {
        message.line3 = "The foe is vanquished.";
      }
  }

}

void fightTurnCurrentEnemy(Corax::Character character, Corax::Enemy currentEnemy, Corax::Message message) {
  
  
  message.line1 = "The " + currentEnemy.name + " attacks!\n";

}

void winFight(Corax::Message message) {
  message.line1 = "You won!";
}

void loseFight(Corax::Message message) {
  message.line1 = "You Lost!";
  bool isRunning = false;
};

void drawScreen(Corax::Character character, Corax::Message message) {
  drawTopScreenUI(character);
  drawPortraits();
  drawBottomScreenUI(message);
}

void gameStart(Corax::Character character, Corax::Message message) {
  char temp = '\0';
  do {
    drawScreen(character, message);
    std::cout << "Press any button to start";
    std::cin >> temp;
  } while (temp == '\0');

}
