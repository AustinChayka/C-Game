#include "PossesedNail.h"

#include "NailObject.h"

PossesedNail::PossesedNail() : UseableItem("assets/Items/PossesedNail.png", "Possesed Nail", "get bent.") {}

PossesedNail::~PossesedNail() {}

bool PossesedNail::OnUse(LevelManager * game, Player * p) {

	game->AddObject(new NailObject(p->GetDir() == -1 ? p->GetX() - 2 : p->GetX() + p->GetWidth(), p->GetY() + 14 * 3,
		p->GetVX() + 10 * p->GetDir(), p->GetVY() - 5));
	
	return true;

}
