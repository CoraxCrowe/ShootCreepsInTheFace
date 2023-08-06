#ifndef __CORAX_MAIN_H_
#define __CORAX_MAIN_H_

#include <string>

#include "Character.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Message.h"

void gameStart(Corax::Character character, Corax::Message message);
void drawTopScreenUI(Corax::Character character);
void drawPortraits();
void drawBottomScreenUI(Corax::Message message);
void drawScreen(Corax::Character character, Corax::Message message);

Corax::Enemy pickEnemy(Corax::Enemy currentEnemy, Corax::Message message);
void startFight(Corax::Character character, Corax::Enemy currentEnemy, Corax::Message message);
void fightTurnPlayer(Corax::Character character, Corax::Enemy currentEnemy, Corax::Message message);
void fightTurnCurrentEnemy(Corax::Character character, Corax::Enemy currentEnemy, Corax::Message message);

void useBomb();
void useKnife();
void useWeapon();
void reloadWeapon();

void winFight(Corax::Message message);
void loseFight(Corax::Message message);

#endif