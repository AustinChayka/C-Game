#ifndef Pot_h
#define Pot_h

#include "GameObject.h"

class Pot : public GameObject {

public:

	Pot(float x, float y, bool init_solid);

	~Pot();

	void OnDeath(LevelManager * game);

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

};

#endif