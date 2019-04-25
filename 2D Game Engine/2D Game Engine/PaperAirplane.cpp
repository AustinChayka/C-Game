#include "PaperAirplane.h"


PaperAirplane::PaperAirplane() : Item("assets/Items/PaperAirplane.png", "Paper Airplane", "destructive at range"){}

PaperAirplane::~PaperAirplane() {}

void PaperAirplane::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {

	proj->SetMaxdDistance(proj->GetMaxDistance() * 2);

}

void PaperAirplane::UpdateProjectile(LevelManager * game, Player * p, Projectile * proj) {
		
	proj->SetDamage(1 + (int)(proj->DistanceTraveled() / 300.0f));
	proj->SetScale(1 + proj->DistanceTraveled() / 300.0f);
	
}
