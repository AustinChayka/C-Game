#ifndef Slime_h
#define Slime_h

#include "Enemy.h"

#include "Player.h"

class Slime : public Enemy {

public:

	Slime(float x, float y, int size);

	~Slime();
	
	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	void OnDeath(LevelManager * game);

	bool OverrideCollision(GameObject * go);

private:

	int jumpDelay = 0;
	bool split = false;

};

#endif