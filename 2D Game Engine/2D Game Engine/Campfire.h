#ifndef Campfire_h
#define Campfire_h

#include "GameObject.h"

class Campfire : public GameObject {

public:

	Campfire(float x, float y);

	~Campfire();

	void Update(LevelManager * game);

private:

	int delay = 0;

};

#endif