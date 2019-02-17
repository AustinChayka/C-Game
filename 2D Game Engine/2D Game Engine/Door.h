#ifndef Door_h
#define Door_h

#include "GameObject.h"

#include "Player.h"
#include "Room.h"

class Door : public GameObject {

public:

	Door(Room * init_room, float x, float y);

	~Door();

	void Update(LevelManager * game);
	void UpdateObject(LevelManager * game);
	void RenderObject();

private:

	bool closed = true, collided = false;

	SDL_Texture * text;
	SDL_Rect textRect;

	Room * room;
	
};

#endif