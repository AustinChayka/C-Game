#ifndef Fireball_h
#define Fireball_h

#include "Projectile.h"

#include "Ember.h"

class Fireball : public Projectile {

public:

	Fireball(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir, GameObject * init_spawner);

	~Fireball();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

private:

	int particleDelay = 12;
	bool embers = true;

};

#endif