#ifndef MarkOfHunger_h
#define MarkOfHunger_h

#include "Item.h"

class MarkOfHunger : public Item {

public:

	MarkOfHunger();

	~MarkOfHunger();

	virtual void OnKill(LevelManager * game, Player * p, GameObject * go);

};

#endif