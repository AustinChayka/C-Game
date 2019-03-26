#include "BleedStatus.h"

#include "Particle.h"

BleedStatus::BleedStatus(int i) : Status("assets/Icons/BleedIcon.png", i) {

	lifeTime = 20;

}

BleedStatus::~BleedStatus() {}

void BleedStatus::OnApply(GameObject * go) {}

void BleedStatus::OnIncrement(GameObject * go, LevelManager * game) {

	go->DealDamage(increment + 1, game);
	Particle * particle;
	for(int i = 0; i < rand() % 5 + 7; i++) {
		particle = new Particle(go->GetXCenter() + rand() % 20 - 10, go->GetYCenter() + rand() % 20 - 10, 5, 5, 255, 0, 0, 100);
		particle->SetVY(-(rand() % 3 + 5));
		particle->SetVX(rand() % 10 - 5);
		game->AddObject(particle);
	}

}

void BleedStatus::OnEnd(GameObject * go, LevelManager * game) {}

void BleedStatus::OnUpdate(GameObject * go, LevelManager * game) {}
