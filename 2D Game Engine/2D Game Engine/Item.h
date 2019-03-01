#ifndef Item_h
#define Item_h

#include "LevelManager.h"
#include "Player.h"
#include "SDL.h"

class Item {

public:

	Item(const char * iconPath, const char * name, const char * itemFlavor);

	virtual void Update(LevelManager * game, Player * p);
	virtual void OnPickup(LevelManager * game, Player * p);
	virtual void OnDamageTaken(LevelManager * game, GameObject * go, Player * p);
	virtual void OnShotFired(LevelManager * game, Player * p);
	virtual void Render();

	SDL_Texture * GetTexture();
	SDL_Texture * GetNameText();
	SDL_Texture * GetFlavorText();

	int GetNameLength();
	int GetFlavorTextLength();

	~Item();

protected:

	SDL_Texture * icon;
	SDL_Texture * nameText;
	SDL_Texture * flavorText;

	int nameLength;
	int flavorTextLength;

};

#endif