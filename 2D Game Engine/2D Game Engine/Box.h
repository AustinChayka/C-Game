#ifndef Box_h
#define Box_h

#include "GameObject.h"

class Box : public GameObject {

public:

	Box(float x, float y);

	~Box();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go);

};

#endif