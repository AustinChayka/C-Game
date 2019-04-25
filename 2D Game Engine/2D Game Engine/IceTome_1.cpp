#include "IceTome_1.h"

#include "IceShard.h"

IceTome_1::IceTome_1() : Book("assets/Items/IceTome_1.png", "Ice Tome I", "where's my super suit?") {}

IceTome_1::~IceTome_1() {}

bool IceTome_1::OverrideDefaultProjectile(Player * p, Projectile *& proj) {

	delete proj;

	proj = new IceShard(p->GetDir() == -1 ? p->GetX() : p->GetX() + p->GetWidth(),
		p->GetY() + 14 * 3, p->GetVX() + 10 * p->GetDir(), p->GetVY(), p->GetDir(), 0, p, 5);

	return true;

}
