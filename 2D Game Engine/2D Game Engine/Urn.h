#ifndef Urn_h
#define Urn_h

#include "GameObject.h"

class Urn : public GameObject {

public:

	Urn(float x, float y);

	~Urn();

	void Update(LevelManager * game);

	void OnDeath(LevelManager * game, GameObject * go);
	
private:

	int spawns = 0, delay = 60;

};

#endif