#include "DoubleVision.h"

#include "Fireball.h"
#include "IceShard.h"
#include "CursedFireball.h"
#include "SpiritProjectile.h"
#include "Fireball2.h"
#include "WraithProjectile.h"

DoubleVision::DoubleVision() : Item("assets/Items/Glasses.png", "Glasses", "double vision") {}

DoubleVision::~DoubleVision() {}

void DoubleVision::OnShotFired(LevelManager * game, Player * p, Projectile *& proj) {

	Projectile * newProj;
		
	if(dynamic_cast<Fireball2 *>(proj) != nullptr) newProj = new Fireball2(proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
	else if(dynamic_cast<Fireball *>(proj) != nullptr) newProj = new Fireball(proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
	else if(dynamic_cast<CursedFireball *>(proj) != nullptr) newProj = new CursedFireball(proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
	else if(dynamic_cast<IceShard *>(proj) != nullptr) newProj = new IceShard(proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p, proj->GetScale());
	else if(dynamic_cast<WraithProjectile *>(proj) != nullptr) newProj = new WraithProjectile(proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
	else if(dynamic_cast<SpiritProjectile *>(proj) != nullptr) newProj = new SpiritProjectile(proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p, p);
	else newProj = new Projectile("assets/Other/DefaultProjectile.png", proj->GetX(), proj->GetY(),
		proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);

	proj->SetVY(proj->GetVY() + -.5f);
	newProj->SetVY(newProj->GetVY() + .5f);
	newProj->SetBounces(proj->GetBounces());
	game->AddObject(newProj);

}
