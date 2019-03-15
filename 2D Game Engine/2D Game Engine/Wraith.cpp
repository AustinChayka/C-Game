#include "Wraith.h"

#include "Player.h"
#include "Particle.h"

Wraith::Wraith(float x, float y) : Enemy("assets/Wraith.png", x, y, 11, 38, 2, 3) {
	
	collidable = true;
	solid = false;
	moveable = false;

	renderLayer = 3;

}

Wraith::~Wraith() {}

void Wraith::Update(LevelManager * game) {

	Enemy::Update(game);

	if(target == nullptr) for(auto go : *game->GetObjects()) if(dynamic_cast<Player *>(go) && DistanceToSquared(go) > 400 * 400)
		target = go;

	if(target == nullptr) return;

	vX += speed * (target->GetX() - x);
	vY += speed * (target->GetY() - y);
	
	if(vX > maxSpeed) vX = maxSpeed;
	if(vY > maxSpeed) vY = maxSpeed;
	if(vX < -maxSpeed) vX = -maxSpeed;
	if(vY < -maxSpeed) vY = -maxSpeed;

	if(delay == 0) {
		Particle * p = new Particle("assets/Wraith.png", x, y, 11, 38, 0, 0, 2);
		p->SetFadeSpeed(7);
		game->AddObject(p);
		delay = 4;
	} else delay--;

	/*tileX += 0.1f;
	if(tileX > 6) tileX = 0;*/

}

void Wraith::OnCollision(GameObject * go, LevelManager * game) {

	if(!go->IsDamagable()) return;

	go->DealDamage(1, game, this);
	
}
