#include <iostream>
#include <ctime>
#include <string>

#include "Main.h"
#include "Character.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Message.h"

#include "Lunze.h"
#include "Lion.h"
#include "Shewolf.h"



int main() {
  bool isRunning = true;
  Corax::Message message;
  Corax::Enemy currentEnemy;
  Corax::Character character;
  Corax::Weapon weapon;
  
  srand(time(NULL));

    drawScreen(character, message);

    gameStart();    

    while(isRunning) {
        
    pickEnemy(currentEnemy, message);
    drawScreen(character, message);
    pressToAdvance();
    

    startFight(character, currentEnemy, message);
    drawScreen(character, message);
    pressToAdvance();

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

void pickEnemy(Corax::Enemy currentEnemy, Corax::Message message) {
  
  int enemyType;
  
  enemyType = rand() % 3;

  switch (enemyType) {
    case 0: 
      currentEnemy = lunze;
      break;
    case 1: 
      currentEnemy = lion;
      break;
    case 2: 
      currentEnemy = shewolf;
      break;
  }
  std::cout << "picked " << currentEnemy.name;

  currentEnemy.hp += int(currentEnemy.numberOfEnemiesEncountered * 1.2);
  currentEnemy.atk += int(currentEnemy.numberOfEnemiesEncountered * 0.2);
  
  message.setStrings(currentEnemy.pickLine1,
      currentEnemy.pickLine2,
      currentEnemy.pickLine3);
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

void gameStart() {
  
  pressToAdvance();

}

void pressToAdvance () {
  std::cout << "Func called..";
  char temp = '\0';
  do {
    std::cout << "Press any button to advance";
    std::cin >> temp;
  } while (temp == '\0');

  std::cout << "Advancing..";
}
