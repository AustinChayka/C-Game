#ifndef WeightedDice_h
#define WeightedDice_h

#include "Item.h"

class WeightedDice : public Item {

public:

	WeightedDice();

	~WeightedDice();

	void OnPickup(LevelManager * game, Player * p);

};

#endif