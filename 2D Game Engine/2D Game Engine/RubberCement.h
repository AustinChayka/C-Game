#ifndef RubberCement_h
#define RubberCement_h

#include "Item.h"

class RubberCement : public Item {

public:

	RubberCement();

	~RubberCement();

	void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);

};

#endif