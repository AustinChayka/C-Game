#ifndef HealthPotion_h
#define HealthPotion_h

#include "UseableItem.h"

class HealthPotion : public UseableItem {

public:

	HealthPotion();

	~HealthPotion();

	bool OnUse(LevelManager * game, Player * p);

};

#endif