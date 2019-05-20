#ifndef Boss_h
#define Boss_h

#include "Enemy.h"

#include "Item.h"

class Boss : public Enemy {

public:

	Boss(const char * filepath, float x, float y, int width, int height, float scale, int h, const char * name);
	Boss(const char * filepath, float x, float y, int width, int height, float scale, int h, const char * name,
		int init_red, int init_green, int init_blue);

	~Boss();

	virtual void Update(LevelManager * game);
	virtual void RenderObject(int l);

	virtual void OnDeath(LevelManager * game, GameObject * go);

protected:

	SDL_Texture * nameText;
	SDL_Rect barRect, textRect;

	Item * item;

	Uint8 red = 255, green = 255, blue = 255;

	bool init = true;

};

#endif