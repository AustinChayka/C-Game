#ifndef IceTome_1_h
#define IceTome_1_h

#include "Book.h"

class IceTome_1 : public Book {

public:

	IceTome_1();

	~IceTome_1();

	bool OverrideDefaultProjectile(Player * p, Projectile *& proj);

};

#endif