#ifndef FireTome_1_h
#define FireTome_1_h

#include "Book.h"

class FireTome_1 : public Book {

public:

	FireTome_1();

	~FireTome_1();
	
	bool OverrideDefaultProjectile(Player * p, Projectile *& proj);

};

#endif