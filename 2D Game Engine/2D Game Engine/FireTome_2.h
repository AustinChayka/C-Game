#ifndef FireTome_2_h
#define FireTome_2_h

#include "Book.h"

class FireTome_2 : public Book {

public:

	FireTome_2();

	~FireTome_2();

	bool OverrideDefaultProjectile(Player * p, Projectile *& proj);

};

#endif