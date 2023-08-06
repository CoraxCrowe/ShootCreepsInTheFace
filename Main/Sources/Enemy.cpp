#include <string>
#include "Enemy.h"
#include "Character.h"
#include "Message.h"

Corax::Enemy::Enemy() {
}

Corax::Enemy::Enemy(std::string name, int hp, int atk, int atkType) {
    this->name = name;
    this->hp = hp;
    this->atk = atk;
    this->atkType = atkType;
}

void Corax::Enemy::inflictDamage(Corax::Character character,Corax::Message message) {
    
}

void Corax::Enemy::takeDamage(int damage, int hp) {
    this->hp -= damage;
}