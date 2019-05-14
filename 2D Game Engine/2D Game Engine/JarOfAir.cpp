#include "JarOfAir.h"

JarOfAir::JarOfAir() : Item("assets/Items/JarOfAir.png", "Jar of Air", "you feel lighter"){}

JarOfAir::~JarOfAir() {}

void JarOfAir::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetMaxJumps(p->GetMaxJumps() + 1);
	p->SetMaxSpeed(p->GetMaxSpeed() * 1.3f);
	p->SetAcceleration(p->GetAcceleration() * 1.3f);
	p->SetGrav(p->GetGrav() * .7f);
	p->SetDecceleration(p->GetDecceleration() * .7f);

}
