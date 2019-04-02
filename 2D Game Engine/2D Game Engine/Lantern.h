#ifndef Lantern_h
#define Lantern_h

#include "GameObject.h"

class Lantern : public GameObject {

public:

	Lantern(float x, float y);

	~Lantern();

	void Update(LevelManager * game);

	void OnDeath(LevelManager * game, GameObject * go);

private:

	int spawns = 0, delay = 60;

};

#endif