#ifndef Wraith_h
#define Wraith_h

#include "Enemy.h"

class Wraith : public Enemy {

public:

	Wraith(float x, float y);

	~Wraith();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	bool OverrideStatus(Status * s);

	bool OverrideCollision(GameObject * go);

private:

	float speed = .01f, maxSpeed = 7.5f;

	int delay = 3;

};

#endif