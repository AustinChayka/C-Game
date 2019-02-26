#ifndef Item_h
#define Item_h

#include "LevelManager.h"
#include "Player.h"
#include "SDL.h"

class Item {

public:

	Item(const char * iconPath, const char * name);

	virtual void Update(LevelManager * game, Player * p);
	virtual void OnPickup(LevelManager * game, Player * p);
	virtual void OnDamageTaken(LevelManager * game, GameObject * go, Player * p);
	virtual void OnShotFired(LevelManager * game, Player * p);

	SDL_Texture * GetTexture();

	~Item();

protected:

	SDL_Texture * icon;
	SDL_Texture * nameText;

};

#endif