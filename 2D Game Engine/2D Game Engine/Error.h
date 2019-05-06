#ifndef Error_h
#define Error_h

#include "Book.h"

class Error : public Book {

public:

	Error();

	~Error();

	bool OverrideDefaultProjectile(Player * p, Projectile *& proj);
	void OnDamageDelt(LevelManager * game, Player * p, GameObject * go);

};

#endif