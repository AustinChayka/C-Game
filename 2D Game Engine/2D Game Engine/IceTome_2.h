#ifndef IceTome_2_h
#define IceTome_2_h

#include "Book.h"

class IceTome_2 : public Book {

public:

	IceTome_2();

	~IceTome_2();

	bool OverrideDefaultProjectile(Player * p, Projectile *& proj);

};

#endif