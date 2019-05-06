#ifndef BloatedDoll_h
#define BloatedDoll_h

#include "Item.h"

class BloatedDoll : public Item {

public:

	BloatedDoll();

	~BloatedDoll();

	void OnKill(LevelManager * game, Player * p, GameObject * go);

};

#endif