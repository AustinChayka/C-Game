#include "FireTome_2.h"

#include "Fireball2.h"

FireTome_2::FireTome_2() : Book("assets/Items/FireTome_2.png", "Fire Tome II", "anarchist's cookbook") {}

FireTome_2::~FireTome_2() {}

bool FireTome_2::OverrideDefaultProjectile(Player * p, Projectile *& proj) {

	delete proj;

	proj = new Fireball2(p->GetDir() == -1 ? p->GetX() : p->GetX() + p->GetWidth(),
		p->GetY() + 14 * 3, p->GetVX() + 10 * p->GetDir(), p->GetVY(), p->GetDir(), 0, p);

	return true;

}
