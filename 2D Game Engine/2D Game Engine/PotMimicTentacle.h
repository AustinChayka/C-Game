#ifndef PotMimicTentacle_h
#define PotMimicTentacle_h

#include "Enemy.h"

class PotMimicTentacle : public Enemy {

public:

	PotMimicTentacle(float x, float y);

	~PotMimicTentacle();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);
	
private:

	int statusFlag = 0;

};

#endif