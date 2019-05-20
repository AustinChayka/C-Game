#ifndef Librarian_h
#define Librarian_h

#include "Boss.h"
#include <vector>

class Librarian : public Boss {

public:

	Librarian(float x, float y);

	~Librarian();

	void Update(LevelManager * game);

	bool OverrideCollision(GameObject * go);

	void OnDeath(LevelManager * game, GameObject * go);

private:

	int spawnDelay = 0, subSpawn = 10, spawns = 3, maxSpawns = 3, telportDelay = 60 * 8, 
		shootDelay = 0, shootSubDelay = 30, shotCount = 2, phase = 0;
	float spawnX, spawnY;

	std::vector<GameObject *> spirits;

};

#endif