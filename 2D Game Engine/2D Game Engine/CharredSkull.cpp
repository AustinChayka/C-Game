#include "CharredSkull.h"

#include "WraithProjectile.h"
#include "CursedFireball.h"

CharredSkull::CharredSkull() : Item("assets/Items/CharredSkull.png", "Charred Skull", "who did it belong to?") {}

CharredSkull::~CharredSkull() {}

void CharredSkull::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {

	if(rand() % 3 == 0) {

		delete proj;

		proj = new WraithProjectile(p->GetDir() == -1 ? p->GetX() : p->GetX() + p->GetWidth(),
			p->GetY() + 14 * 3, p->GetVX() + 7 * p->GetDir(), p->GetVY(), p->GetDir(), 0, p);

	}

}
