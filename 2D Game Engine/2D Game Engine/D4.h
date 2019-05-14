#ifndef D4_h
#define D4_h

#include "Item.h"

class D4 : public Item {

public:

	D4();

	~D4();

	void OnPickup(LevelManager * game, Player * p);
	void OnDamageDelt(LevelManager * game, Player * p, GameObject * go, bool crit);

};

#endif 