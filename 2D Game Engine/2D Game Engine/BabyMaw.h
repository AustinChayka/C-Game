#ifndef BabyMaw_h
#define BabyMaw_h

#include "Item.h"

class BabyMaw : public Item {

public:

	BabyMaw();

	~BabyMaw();

	void OnPickup(LevelManager * game, Player * p);
	void UpdateMaw(LevelManager * game, Player * p);
	void Update(LevelManager * game, Player * p);
	void Render();

private:

	float x, y, vX = 0, vY = 0, width, height, tileX = 0;
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

	int shotDelay = 20, chargeDelay = 120, shots = 3;

	GameObject * target;

	float GetXCenter();
	float GetYCenter();

	float DistanceToSquared(GameObject * go);

};

#endif