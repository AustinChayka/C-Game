#ifndef Corpse_h
#define Corpse_h

#include "GameObject.h"

class Corpse : public GameObject {

public:

	Corpse(const char * filepath, float x, float y, int width, int height, int init_tileX, int init_tileY, float scale);

	~Corpse();

	void Update(LevelManager * game);

	bool OverrideCollision(GameObject * go);

private:

	const char * path;

	int img_width, img_height, delay = 20;

};

#endif