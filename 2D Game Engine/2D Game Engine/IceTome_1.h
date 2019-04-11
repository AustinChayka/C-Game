#ifndef IceTome_1_h
#define IceTome_1_h

#include "Item.h"

class IceTome_1 : public Item {

public:

	IceTome_1();

	~IceTome_1();

	bool OverrideDefaultProjectile(Player * p, Projectile *& proj);

};

#endif