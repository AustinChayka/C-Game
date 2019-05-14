#include "SacraficialDagger.h"

#include "SpiritProjectile.h"
#include "SpiritProjectile2.h"
#include "CharredSkull.h"

SacraficialDagger::SacraficialDagger() : Item("assets/Items/SacraficialDagger.png", "Sacraficial Dagger", 
	"the ritual has begun") {

	synergy = typeid(CharredSkull).name();

}

SacraficialDagger::~SacraficialDagger() {}

void SacraficialDagger::OnKill(LevelManager * game, Player * p, GameObject * go) {

	kills++;
	if(kills % 10 == 0 && kills > 0) Game::gui->ShowMessage("the dagger thirsts for more", 255, 255, 255, 255, 150);

	for(int i = 0; i < 2 + (kills / 10); i++) {
		if(synergyActive) game->AddObject(new SpiritProjectile2(go->GetXCenter(), go->GetYCenter(), rand() % 8 - 4,
			rand() % 8 - 4, 0, 0, p, go));
		else game->AddObject(new SpiritProjectile(go->GetXCenter(), go->GetYCenter(), rand() % 8 - 4, rand() % 8 - 4,
			0, 0, p, go));
	}

}
