#ifndef HealthPotion_h
#define HealthPotion_h

#include "UseableItem.h"

class HealthPotion : public UseableItem {

public:

	HealthPotion();

	~HealthPotion();

	bool OnUse(LevelManager * game, Player * p);
	void Update(LevelManager * game, Player * p);

	void Render();

private:

	int charges = 1, maxCharges = 1;

	SDL_Rect destRect;

};

#endif