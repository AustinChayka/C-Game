#ifndef Fire_h
#define Fire_h

#include "GameObject.h"

class Fire : public GameObject {

public:

	Fire(float x, float y, float scale);
	~Fire();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go);

private:

	float lifeTime = -1;

};

#endif