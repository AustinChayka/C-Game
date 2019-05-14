#include "Error.h"

#include "Enemy.h"

#include "Fireball.h"
#include "Fireball2.h"
#include "IceShard.h"
#include "MawProjectile.h"
#include "SpiritProjectile.h"
#include "WraithProjectile.h"
#include "IceShard2.h"

#include "BleedStatus.h"
#include "ChilledStatus.h"
#include "CursedFireStatus.h"
#include "FireStatus.h"
#include "PoisonStatus.h"
#include "RegenStatus.h"

Error::Error() : Book("assets/Items/Error.png", "ErR0R", "nullptr") {}

Error::~Error() {}

bool Error::OverrideDefaultProjectile(Player * p, Projectile *& proj) {

	Projectile * oldProj = proj;

	switch(rand() % 8) {

		case 0:
			proj = new Projectile("assets/Other/DefaultProjectile.png", proj->GetX(), proj->GetY(),
				proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
			break;

		case 1:
			proj = new Fireball(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
			break;

		case 2:
			proj = new Fireball2(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
			break;

		case 3:
			proj = new IceShard(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), 
				p, proj->GetScale());
			break;

		case 4:
			proj = new MawProjectile(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
			break;

		case 5:
			proj = new SpiritProjectile(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), 
				p, p);
			break;

		case 6:
			proj = new WraithProjectile(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), p);
			break;

		case 7:
			proj = new IceShard2(proj->GetX(), proj->GetY(), proj->GetVX(), proj->GetVY(), proj->GetXDir(), proj->GetYDir(), 
				p, proj->GetScale());
			break;

	}

	delete oldProj;

	return true;

}

void Error::OnDamageDelt(LevelManager * game, Player * p, GameObject * go) {

	if(dynamic_cast<Enemy *>(go) != nullptr) {

		Status * s = new BleedStatus(1);

		switch(rand() % 6) {
		
			case 1:
				s = new ChilledStatus(1);
				break;

			case 2:
				s = new CursedFireStatus(1);
				break;

			case 3:
				s = new FireStatus(1);
				break;

			case 4:
				s = new PoisonStatus(1);
				break;

			case 5:
				s = new RegenStatus(1);
				break;

		}

		((Enemy *)go)->AddStatus(s);

	}

}
