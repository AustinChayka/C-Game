#ifndef Player_h
#define Player_h

#include "GameObject.h"

class Player : public GameObject {

public:

	Player(float x, float y);
	~Player();
	
	void Update(LevelManager * game);

private:

	bool left = false, right = false;

	float maxSpeed = 7, acceleration = .6f, decceleration = 1.15f, jumpPower = 13.5f;

	int dir = 1, shotDelay = 30, shot = 0;

};

#endif