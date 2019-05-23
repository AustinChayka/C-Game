#ifndef SentientSword_h
#define SentientSword_h

#include "Item.h"

class SentientSword : public Item {

public:

	SentientSword();

	~SentientSword();

	void Update(LevelManager * game, Player * p);
	void OnPickup(LevelManager * game, Player * p);
	void Render();

private:

	float x, y, vX, vY;
	int damageDelay = 0, attackDelay = 0, attack = 0;

	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;

	void UpdateSword(LevelManager * game, Player * p);

	float DistanceToSquared(GameObject * go);
	float GetXCenter();
	float GetYCenter();

	GameObject * target;

};

#endif