#include <string>
#include "Enemy.h"

Corax::Enemy::Enemy() {
}

Corax::Enemy::Enemy(std::string name, int hp, int atk, int atkType) {
    this->name = name;
    this->hp = hp;
    this->atk = atk;
    this->atkType = atkType;
}

int Corax::Enemy::inflictDamage(int damage, int atkType) {
    return damage;
}

void Corax::Enemy::takeDamage(int damage, int hp) {
    this->hp -= damage;
}