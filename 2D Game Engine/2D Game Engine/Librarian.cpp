#include "Librarian.h"

#include "Spirit.h"
#include "Debris.h"
#include "WraithProjectile.h"

Librarian::Librarian(float x, float y) : Boss("assets/Enemies/Librarian.png", x, y, 25, 45, 3, 75, "Fanatic Librarian") {

	collidable = true;
	solid = false;
	moveable = false;

	spawnX = x;
	spawnY = y;

}

Librarian::~Librarian() {}

void Librarian::Update(LevelManager * game) {

	Enemy::Update(game);

	if(target == nullptr) for(auto go : *game->GetObjects()) if(dynamic_cast<Player*>(go) != nullptr && DistanceToSquared(go) < 40000) {
		target = go;
		break;
	} else if(!target || target->IsDead()) target = nullptr;

	for(int i = 0; i < spirits.size(); i++) 
		if(spirits.at(i)->IsDead()) 
			spirits.erase(spirits.begin() + i);

	if(spawnDelay > 0) {
		if(spirits.size() == 0) spawnDelay--;
	} else {
		if(subSpawn > 0) subSpawn--;
		else if(spawns > 0) {
			Spirit * s = new Spirit(GetXCenter(), GetYCenter());
			s->SetParent(this);
			s->SetProjectileDelay(maxSpawns == 3 ? 180 * 3 : 180 * 2);
			s->SetDeg(180 * spirits.size() / (float)maxSpawns);
			spirits.push_back(s);
			game->AddObject(s);
			subSpawn = 60;
			spawns--;
		} else {
			spawnDelay = 300;
			if(health < maxHealth / 2) maxSpawns = 5;
			spawns = maxSpawns;
		}
	}
	
	if(telportDelay > 0) telportDelay--;
	else {
		game->AddObject(new Debris("assets/Enemies/Librarian.png", 20, 30, tileX, tileY, 3, x, y));
		if(x == spawnX) {
			switch(rand() % 2) {
				case 0:
					x = spawnX - 6 * 60;
					break;
				case 1:
					x = spawnX + 6 * 60;
					break;
			}
		} else if(x == spawnX + 6 * 60) {
			switch(rand() % 2) {
				case 0:
					x = spawnX;
					break;
				case 1:
					x = spawnX - 6 * 60;
					break;
			}
		} else if(x == spawnX - 6 * 60) {
			switch(rand() % 2) {
				case 0:
					x = spawnX;
					break;
				case 1:
					x = spawnX + 6 * 60;
					break;
			}
		}
		telportDelay = health > maxHealth / 2 ? 60 * 8 : 60 * 5;
	}

	if(target == nullptr) return;

	if(shootDelay > 0) shootDelay--;
	else {
		if(shootSubDelay > 0) shootSubDelay--;
		else if(shotCount > 0) {
			Projectile * p = new WraithProjectile(target->GetX() > x ? x + width : x, GetYCenter(),
				target->GetX() > x ? 10 : -10, 0, target->GetX() > x ? 1 : -1, 0, this);
			p->SetDamage(2);
			game->AddObject(p);
			shootSubDelay = 20;
			shotCount--;
		} else {
			shootDelay = spirits.size() == 0 ? 180 : 360;
			shotCount = 3;
		}
	}

}
