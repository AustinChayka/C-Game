#include "CrownOfThorns.h"

#include "BleedStatus.h"

CrownOfThorns::CrownOfThorns() : Item("assets/Items/CrownOfThorns.png", "Crown of Thorns", "pointy") {}

CrownOfThorns::~CrownOfThorns() {}

void CrownOfThorns::Update(LevelManager * game, Player * p) {

	if(delay > 0) delay--;
	else {
		for(auto go : *game->GetObjects()) if(p->CollidesWith(go) && go->IsDamagable()) {
			delay = 60;
			go->DealDamage(1, game, p);
			if(dynamic_cast<Enemy *>(go) != nullptr) ((Enemy *)go)->AddStatus(new BleedStatus(2));
		}
	}

}
