#include "Heart.h"

#include "Particle.h"
#include <cmath>

Heart::Heart() : Item("assets/Items/Heart.png", "Heart Crystal", "you feel healthy") {}

void Heart::OnPickup(LevelManager * game, Player * p) {

	p->SetMaxHealth(p->GetMaxHealth() + 6);
	p->Heal(6);

}

void Heart::OnDamageTaken(LevelManager * game, GameObject * go, Player * p) {

	if(rand() % 20 == 0) {
		Particle * particle;
		p->Heal(1);
		for(int i = 0; i < rand() % 5 + 7; i++) {
			particle = new Particle(p->GetXCenter() + rand() % 20 - 10, p->GetYCenter() + rand() % 20 - 10, 5, 5, 255, 0, 0, 100);
			particle->SetVY(-(rand() % 3 + 5));
			particle->SetVX(rand() % 10 - 5);
			game->AddObject(particle);
		}
	}

}

Heart::~Heart() {}
