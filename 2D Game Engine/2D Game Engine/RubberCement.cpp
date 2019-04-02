#include "RubberCement.h"

RubberCement::RubberCement() : Item("assets/Items/RubberCement.png", "Rubber Cement", "physics++") {}

RubberCement::~RubberCement() {}

void RubberCement::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {

	proj->SetVY(proj->GetVY() - .03f * 20);
	proj->SetBounces(proj->GetBounces() + 3);
	proj->SetGrav(proj->GetGrav() + .03f);

}
