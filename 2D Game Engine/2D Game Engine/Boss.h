#ifndef Boss_h
#define Boss_h

#include "Enemy.h"

#include "Item.h"

class Boss : public Enemy {

public:

	Boss(const char * filepath, float x, float y, int width, int height, float scale, int h, const char * name);

	~Boss();

	virtual void RenderObject();

	virtual void OnDeath(LevelManager * game, GameObject * go);

protected:

	SDL_Texture * nameText;
	SDL_Rect barRect, textRect;

	Item * item;

};

#endif