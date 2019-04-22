#ifndef SacraficialAltar_h
#define SacraficialAltar_h

#include "GameObject.h"

class SacraficialAltar : public GameObject {

public:

	SacraficialAltar(float x, float y);

	~SacraficialAltar();

	void Update(LevelManager * game);
	void RenderObject();

private:

	bool collided = false, active = true;

	SDL_Texture * text;
	SDL_Rect destRect;

};

#endif