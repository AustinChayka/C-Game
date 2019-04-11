#include "FireTome_1.h"

#include "Fireball.h"

FireTome_1::FireTome_1() : Item("assets/Items/FireTome_1.png", "Fire Tome I", "pyromancy 101") {}

FireTome_1::~FireTome_1() {}

bool FireTome_1::OverrideDefaultProjectile(Player * p, Projectile *& proj) {

	delete proj;

	proj = new Fireball(p->GetDir() == -1 ? p->GetX() : p->GetX() + p->GetWidth(),
		p->GetY() + 14 * 3, p->GetVX() + 10 * p->GetDir(), p->GetVY(), p->GetDir(), 0, p);

	return true;

}
