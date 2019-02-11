#ifndef Fire_h
#define Fire_h

#include "GameObject.h"

class Fire : public GameObject {

public:

	Fire(float x, float y, float scale, GameObject * init_spawner);
	~Fire();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

private:

	float lifeTime = -1;

	GameObject * spawner;

};

#endif