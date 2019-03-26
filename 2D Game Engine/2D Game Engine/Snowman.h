#ifndef Snowman_h
#define Snowman_h

#include "Enemy.h"

class Snowman : public Enemy {

public:

	Snowman(float x, float y);

	~Snowman();

	void Update(LevelManager * game);

	bool OverrideCollision(GameObject * go);

private:

	int delay = 0;
	
};

#endif