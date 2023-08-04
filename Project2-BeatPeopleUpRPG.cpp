#include <iostream>
#include <ctime>
#include <string>

class Weapon {
  public:
    std::string name = "gun";
    int ammo;
    int damage;
};

class Enemy {
  public:
    std::string name = "monster";
    int hp = 10;
    int atk = 0;
    int atkType = 0;
    
    Enemy() {

    }

    Enemy(std::string name, int hp, int atk, int atkType) {
      this->name = name;
      this->hp = hp;
      this->atk = atk;
      this->atkType = atkType;
    }

    int inflictDamage(int damage, int atkType) {

      return damage;
    }

    void takeDamage(int damage, int hp) {

      this->hp -= damage;
    }
    
};

class Character {
  public:
    int numberOfHearts = 6;
    int numberOfMaxHearts = 10;
    
    int numberOfBombs = 5;
    int numberOfAmmo = 0;

    Weapon weapon;
};

void drawTopScreenUI(Character character);
void drawScreen();
void drawBottomScreenUI(Enemy currentEnemy);

Enemy pickEnemy(Enemy currentEnemy);
void startFight(Character character, Enemy currentEnemy);
void fightTurnPlayer(Character character);
void fightTurnCurrentEnemy(Enemy currentEnemy);

void useBomb();
void useKnife();
void useWeapon();
void reloadWeapon();

void winFight();

void loseFight();

std::string currentMessageLine1;
std::string currentMessageLine2;
std::string currentMessageLine3;


int main() {
  
  bool isRunning = true;
  Enemy currentEnemy;
  Character character;
  Weapon weapon;
  
  srand(time(NULL));

    while(isRunning) {
        
    currentEnemy = pickEnemy(currentEnemy);

    std::cout << currentEnemy.name;
    
    drawTopScreenUI(character);

    drawScreen();

    drawBottomScreenUI(currentEnemy);

    startFight(character, currentEnemy);

  }


  return 0;
}

void drawBottomScreenUI(Enemy enemy1) {
  
  std::cout << "________________________________________________________________________________\n";
  std::cout << "||                                                                            ||\n";
  std::cout << "                            " << currentMessageLine1 << "                                                    \n";
  std::cout << "                            " << currentMessageLine2 << "                                                    \n";
  std::cout << "                            " << currentMessageLine3 << "                                    \n";
  std::cout << "                                                                                \n";
  std::cout << "                                                                                \n";              
}

void drawTopScreenUI(Character character) {

  char lifebar[] = "1234567890";

  for (int i = 0; i < character.numberOfMaxHearts; i++) {
    if (i < character.numberOfHearts) {
      lifebar[i] = 'O';
    } else {
      lifebar[i] = '-';
    }
  }

  std::cout << "                      ||                                ||                      \n";
  std::cout << "        * x " << character.numberOfBombs << "         ||          [" << lifebar << "]          ||        knife  /      \n";
  std::cout << "______________________||________________________________||______________________\n";

}

void drawScreen () {
  
  for (int i = 0; i < 12; i++) {
    std::cout << "                                                                                \n";
  }
  

}

Enemy pickEnemy(Enemy currentEnemy) {
  
  int enemyType;  

  enemyType = 0; //rand() % 5;

  switch (enemyType) {
    case 0: 
      currentEnemy.name = "Hellhound"; //progressively gets stronger
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

void startFight(Character character, Enemy currentEnemy) {

  while (character.numberOfHearts > 0 && currentEnemy.hp > 0) {

    fightTurnPlayer(character);

    if (currentEnemy.hp > 0) {
      
      fightTurnCurrentEnemy(currentEnemy);
    }

  }

  if (character.numberOfHearts <= 0) {
    loseFight();
  } else {
    winFight();
  }
  

}

void fightTurnPlayer(Character character) {
  
  int optionSelect;
  currentMessageLine1 = "Press 1 to attack\n";
  std::cin >> optionSelect;

  if (optionSelect == 1) {
      currentMessageLine1 = "The warrior attacks\n";
  }

}

void fightTurnCurrentEnemy(Enemy currentEnemy) {
  
  currentMessageLine1 = "The " + currentEnemy.name + " attacks!\n";

}

void winFight() {
  currentMessageLine1 = "You won!";
}

void loseFight() {
  currentMessageLine1 = "You Lost!";
  bool isRunning = false;
};



