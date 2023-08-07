#include <string>
#include "Enemy.h"
#include "Character.h"
#include "Message.h"

Corax::Enemy::Enemy() {
}

Corax::Enemy::Enemy(std::string name, int hp, int atk) {
    
    this->name = name;
    this->hp = hp;
    this->atk = atk;
    

}


