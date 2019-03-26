#ifndef NailObject_h
#define NailObject_h

#include "GameObject.h"

class NailObject : public GameObject {

public:

	NailObject(float x, float y, float init_vX, float init_vY);

	~NailObject();

	void Update(LevelManager * game);

	bool OverrideCollision(GameObject * go);

	void OnCollision(GameObject * go, LevelManager * game);

private:

	int delay = 90;
	
};

#endif