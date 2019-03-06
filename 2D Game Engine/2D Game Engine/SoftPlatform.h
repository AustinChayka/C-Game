#ifndef SoftPlatform_h
#define SoftPlatform_h

#include "GameObject.h"

class SoftPlatform : public GameObject {

public:

	SoftPlatform(float x, float y, int init_tilesWidth);

	~SoftPlatform();

	void Update(LevelManager * game);

	void RenderObject();

	bool OverrideCollision(GameObject * go);

private:

	int tilesWidth;

};

#endif 