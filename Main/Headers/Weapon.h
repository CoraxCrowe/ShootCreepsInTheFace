#ifndef __CORAX_WEAPON_H_
#define __CORAX_WEAPON_H_

#include <string>

namespace Corax {

	class Weapon {
		public:
			std::string name = "gun";
			int ammo;
			int damage;
			void load();
	};

}

#endif