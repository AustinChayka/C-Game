#ifndef Explosion_h
#define Explosion_h

#include "GameObject.h"

class Explosion : public GameObject {

public:

	Explosion(float xCenter, float yCenter, float init_radius, int init_damage, GameObject * init_spawner, LevelManager * game);

	~Explosion();

	void UpdateObject(LevelManager * game);
	void Update(LevelManager * game);
	void RenderObject();

	bool IsInRadius(GameObject * go);

private:

	float radius;
	int damage;
	GameObject * spawner;

};

#endif