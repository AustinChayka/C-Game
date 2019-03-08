#ifndef DemonAlter_h
#define DemonAlter_h

#include "GameObject.h"

class DemonAlter : public GameObject {

public:

	DemonAlter(float x, float y);

	~DemonAlter();

	void Update(LevelManager * game);
	void RenderObject();

private:

	bool collided = false, active = true;

	SDL_Texture * text;
	SDL_Rect destRect;

};

#endif