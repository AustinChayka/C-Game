#ifndef PossesedNail_h
#define PossesedNail_h

#include "UseableItem.h"

class PossesedNail : public UseableItem {

public:

	PossesedNail();

	~PossesedNail();

	bool OnUse(LevelManager * game, Player * p);

};

#endif