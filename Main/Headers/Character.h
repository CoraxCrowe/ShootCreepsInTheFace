#ifndef __CORAX_CHARACTER_H_
#define __CORAX_CHARACTER_H_

#include <string>
#include "Weapon.h"

namespace Corax {

	class Character {
	public:

    int hp = 100;
    int maxhp = 100;

		int numberOfHearts = 10;
		int numberOfMaxHearts = 10;
		
		int numberOfBombs = 5;
		int numberOfAmmo = 0;

		Corax::Weapon weapon;
	};

}

#endif