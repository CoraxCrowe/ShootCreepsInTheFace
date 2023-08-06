#ifndef __CORAX_CHARACTER_H_
#define __CORAX_CHARACTER_H_

#include <string>
#include "Weapon.h"

namespace Corax {

	class Character {
	public:

    int currentHp = 100;
    int maxHp = 100;
		
		int numberOfBombs = 5;
		int numberOfAmmo = 0;

		Corax::Weapon weapon;
	};

}

#endif