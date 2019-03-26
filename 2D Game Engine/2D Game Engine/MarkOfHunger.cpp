#include "MarkOfHunger.h"

#include "Particle.h"

MarkOfHunger::MarkOfHunger()  : Item("assets/Items/MarkOfHunger.png", "Mark of Hunger", "feed your soul") {}

MarkOfHunger::~MarkOfHunger() {}

void MarkOfHunger::OnKill(LevelManager * game, Player * p, GameObject * go) {

	if(rand() % 3 == 0) {
		p->Heal(1);
		Particle * particle;
		for(int i = 0; i < rand() % 5 + 7; i++) {
			particle = new Particle(go->GetXCenter() + rand() % 20 - 10, go->GetYCenter() + rand() % 20 - 10, 5, 5, 255, 0, 0, 100);
			particle->SetVY(-(rand() % 3 + 5));
			particle->SetVX(rand() % 10 - 5);
			game->AddObject(particle);
		}
	}

}
