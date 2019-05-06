#ifndef IceShard2_h
#define IceShard2_h

#include "IceShard.h"

class IceShard2 : public IceShard {

public:

	IceShard2(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner, float init_scale);

	~IceShard2();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

private :

	int delay = 30;

};

#endif