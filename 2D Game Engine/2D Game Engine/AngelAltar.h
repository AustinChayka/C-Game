#ifndef AngelAltar_h
#define AngelAltar_h

#include "GameObject.h"

class AngelAltar : public GameObject {

public:

	AngelAltar(float x, float y);

	~AngelAltar();

	void Update(LevelManager * game);
	void RenderObject();

private:

	bool collided = false, active = true;

	SDL_Rect textRect;
	SDL_Texture * text;

};

#endif