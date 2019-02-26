#include "Heart.h"

Heart::Heart(float x, float y) : Item("assets/Items/Heart.png", "Heart Crystal") {}

void Heart::OnPickup(LevelManager * game, Player * p) {

	p->Heal(3);

}

Heart::~Heart() {}
