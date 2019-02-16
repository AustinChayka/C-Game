#ifndef Door_h
#define Door_h

#include "GameObject.h"

#include "Player.h"

class Door : public GameObject {

public:

	Door(float x, float y);

	~Door();

	void Update(LevelManager * game);
	void UpdateObject(LevelManager * game);
	void RenderObject();

private:

	bool closed = true, collided = false;

	SDL_Texture * text;
	SDL_Rect textRect;
	
};

#endif