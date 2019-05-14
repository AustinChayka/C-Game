#include "WeightedDice.h"

WeightedDice::WeightedDice() : Item("assets/Items/WeightedDice.png", "Weighted Dice", "extra lucky") {}

WeightedDice::~WeightedDice() {}

void WeightedDice::OnPickup(LevelManager * game, Player * p) {

	Item::OnPickup(game, p);

	p->SetCritChance(p->GetCritChance() + 20);

}
