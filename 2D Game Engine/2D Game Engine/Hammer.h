#ifndef Hammer_h
#define Hammer_h

#include "GameObject.h"

class Hammer : public GameObject {

public:

	Hammer(float x, float y);

	~Hammer();

	void Update(LevelManager * game);

	bool OverrideCollision(GameObject * go);

	void OnCollision(GameObject * go, LevelManager * game);

private: 

	int delay = 120;
	bool collided = false;

};

#endif