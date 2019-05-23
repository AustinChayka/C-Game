#ifndef CrownOfThornes_h
#define CrownOfThornes_h

#include "Item.h"

class CrownOfThorns : public Item {

public:

	CrownOfThorns();

	~CrownOfThorns();

	void Update(LevelManager * game, Player * p);

private:

	int delay = 0;

};

#endif