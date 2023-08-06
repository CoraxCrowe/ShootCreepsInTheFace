#ifndef __CORAX_MAIN_H_
#define __CORAX_MAIN_H_

#include <string>

#include "Character.h"
#include "Enemy.h"
#include "Weapon.h"

void drawTopScreenUI(Corax::Character character);
void drawPortraits();
void drawBottomScreenUI(Corax::Message message);
void drawScreen(Corax::Character character, Corax::Message message);

Corax::Enemy pickEnemy(Corax::Enemy currentEnemy);
void startFight(Corax::Character character, Corax::Enemy currentEnemy);
void fightTurnPlayer(Corax::Character character);
void fightTurnCurrentEnemy(Corax::Enemy currentEnemy);

void useBomb();
void useKnife();
void useWeapon();
void reloadWeapon();

void winFight();
void loseFight();

#endif