#ifndef ItemObject_h
#define ItemObject_h

#include "GameObject.h"

#include "Item.h"

class ItemObject : public GameObject {

public:

	ItemObject(float x, float y, int type);

	~ItemObject();

	void Update(LevelManager * game);

	void RenderObject();

private:

	Item * item;
	SDL_Texture * text;
	SDL_Rect textRect;

	bool collided = false;

};

#endif