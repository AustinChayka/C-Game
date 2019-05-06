#include "IceTome_2.h"

#include "IceShard2.h"

IceTome_2::IceTome_2() : 
	Book("assets/Items/IceTome_2.png", "Ice Tome 2", "stay frosty") {}

IceTome_2::~IceTome_2() {}

bool IceTome_2::OverrideDefaultProjectile(Player * p, Projectile *& proj) {
	   
	delete proj;

	proj = new IceShard2(p->GetDir() == -1 ? p->GetX() : p->GetX() + p->GetWidth(),
		p->GetY() + 14 * 3, p->GetVX() + 10 * p->GetDir(), p->GetVY(), p->GetDir(), 0, p, 5);

	return true;

}
