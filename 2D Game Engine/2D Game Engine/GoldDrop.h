#ifndef GoldDrop_h
#define GoldDrop_h

#include "GameObject.h"

class GoldDrop : public GameObject {

public:

	GoldDrop(float x, float y, int init_value);

	~GoldDrop();

	void Update(LevelManager * game);
	void RenderObject();

	void OnCollision(GameObject * go, LevelManager * game);
	bool OverrideCollision(GameObject * go);

private:

	int value;

};

#endif