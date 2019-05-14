#ifndef SacraficialDagger_h
#define SacraficialDagger_h

#include "Item.h"

class SacraficialDagger : public Item {

public:

	SacraficialDagger();

	~SacraficialDagger();

	void OnKill(LevelManager * game, Player * p, GameObject * go);

private:

	int kills;

};

#endif