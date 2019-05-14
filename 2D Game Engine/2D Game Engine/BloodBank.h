#ifndef BloodBank_h
#define BloodBank_h

#include "GameObject.h"

class BloodBank : public GameObject {

public:

	BloodBank(float x, float y);

	~BloodBank();

	void Update(LevelManager * game);
	void RenderObject();

private:

	SDL_Rect textRect;
	SDL_Texture * text;
	bool collided, active = true;

};

#endif