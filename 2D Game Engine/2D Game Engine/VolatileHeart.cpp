#include "VolatileHeart.h"

#include "Explosion.h"
#include "SpiralShell.h"

VolatileHeart::VolatileHeart() : Item("assets/Items/VolatileHeart.png", "Volatile Heart", "hazardous health") {

	synergy = typeid(SpiralShell).name();

}

VolatileHeart::~VolatileHeart() {}

void VolatileHeart::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetMaxHealth(p->GetMaxHealth() + 6);
	p->Heal(6);

}

void VolatileHeart::OnDamageTaken(LevelManager * game, GameObject * go, Player * p) {

	if(explosionDelay == 0) {
		game->AddObject(new Explosion(p->GetXCenter(), p->GetYCenter(), 250, 3, p, game));
		if(synergyActive) {
			Projectile * proj;
			for(int i = 0; i < 15; i++) {
				proj = new Projectile("assets/Other/ShellProjectile.png", p->GetXCenter() + 10 * cos(i * (360.0f / 15) * (M_PI / 180)),
					p->GetYCenter() + 10 * sin(i * (360.0f / 15) * (M_PI / 180)),
					10 * cos(i * (360.0f / 15) * (M_PI / 180)), 10 * sin(i * (360.0f / 15) * (M_PI / 180)), 0, 0, p);
				game->AddObject(proj);
			}
		}
		explosionDelay = 60 * (synergyActive ? 3 : 5);
	}

}

void VolatileHeart::Update(LevelManager * game, Player * p) {

	Item::Update(game, p);

	if(explosionDelay > 0) explosionDelay--;

}
