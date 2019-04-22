#ifndef PotMimic_h
#define PotMimic_h

#include "Enemy.h"

class PotMimic : public Enemy {

public:

	PotMimic(float x, float y);

	~PotMimic();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);

	void DealDamage(int d, LevelManager * game, GameObject * go);

	void OnDeath(LevelManager * game, GameObject * go);

private:

	int statusFlag = -1;
	int delay = 60;

};

#endif