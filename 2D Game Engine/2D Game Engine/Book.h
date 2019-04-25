#ifndef Book_h
#define Book_h

#include "Item.h"

class Book : public Item {

public:

	Book(const char * path, const char * name, const char * flavor);

	~Book();

	virtual void OnPickup(LevelManager * game, Player * p);
	virtual bool OverrideDefaultProjectile(Player * p, Projectile *& proj) = 0;

};

#endif