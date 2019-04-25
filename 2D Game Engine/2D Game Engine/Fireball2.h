#ifndef Fireball2_h
#define Fireball2_h

#include "Fireball.h"

class Fireball2 : public Fireball {

public:

	Fireball2(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner);
	
	~Fireball2();

	void OnCollision(GameObject * go, LevelManager * game);

};

#endif