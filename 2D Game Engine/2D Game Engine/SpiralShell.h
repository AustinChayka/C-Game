#ifndef SpiralShell_h
#define SpiralShell_h

#include "Item.h"

class SpiralShell : public Item {

public:

	SpiralShell();

	~SpiralShell();
	
	int OverrideDamageTotal(int damage, GameObject * go, Player * p);
	void Update(LevelManager * game, Player * p);
	void Render();

private:

	int health = 8, delay = 0;

	SDL_Rect srcRrect, destRect;
	
};

#endif