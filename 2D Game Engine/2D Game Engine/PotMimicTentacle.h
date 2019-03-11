#ifndef PotMimicTentacle_h
#define PotMimicTentacle_h

#include "GameObject.h"

class PotMimicTentacle : public GameObject {

public:

	PotMimicTentacle(float x, float y);

	~PotMimicTentacle();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);
	
private:

	int statusFlag = 0;

};

#endif