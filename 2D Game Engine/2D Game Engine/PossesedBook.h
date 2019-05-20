#ifndef PossesedBook_h
#define PossesedBook_h

#include "Enemy.h"

class PossesedBook : public Enemy {

public:

	PossesedBook(float x, float y);

	~PossesedBook();

	void Update(LevelManager * game);

	void OnCollision(GameObject * go, LevelManager * game);
	void OnDeath(LevelManager * game, GameObject * go);

private:

	int tileDir = 1;

};

#endif