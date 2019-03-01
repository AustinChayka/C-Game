#ifndef CursedCandle_h
#define CrusedCandle_h

#include "Item.h"

class Spirit;

class CursedCandle : public Item {

public:

	CursedCandle();

	virtual void Update(LevelManager * game, Player * p);
	virtual void Render();

	~CursedCandle();

private:

	SDL_Texture * spiritTexture;
	SDL_Rect srcRect, destRect0, destRect1;
	int fireDelay = 0, active = 0;
	float tileX = 0;

	GameObject * target;

};

#endif