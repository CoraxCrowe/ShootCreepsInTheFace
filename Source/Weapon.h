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