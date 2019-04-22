#include "SacraficialDagger.h"

#include "SpiritProjectile.h"

SacraficialDagger::SacraficialDagger() : Item("assets/Items/SacraficialDagger.png", "Sacraficial Dagger", "the ritual has begun") {}

SacraficialDagger::~SacraficialDagger() {}

void SacraficialDagger::OnKill(LevelManager * game, Player * p, GameObject * go) {

	for(int i = 0; i < rand() % 2 + 1; i++) game->AddObject(new SpiritProjectile(go->GetXCenter(), go->GetYCenter(), rand() % 8 - 4, rand() % 8 - 4,
		0, 0, p, go));

}
