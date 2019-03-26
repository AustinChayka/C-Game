#include "WraithProjectile.h"

#include "Particle.h"

WraithProjectile::WraithProjectile(float x, float y, float vX, float vY, int xDir, int yDir, GameObject * spawner) : 
	Projectile("assets/Wraith.png", x, y, vX, vY, xDir, yDir, spawner) {

	width = 19;
	height = 22;

	spriteWidth = width;
	spriteHeight = height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	scale = 1;

	width = width * scale;
	height = height * scale;

	damage = 5;

	amplitude = (rand() % 7 + 3) / 20.0f;

}

void WraithProjectile::Update(LevelManager * game) {

	Projectile::Update(game);

	vY += -cos(distance * M_PI / 180) * amplitude;

	if(delay == 0) {
		Particle * p = new Particle("assets/Wraith.png", x, y, 19, 22, tileX, tileY, 1);
		p->SetFadeSpeed(7);
		game->AddObject(p);
		delay = 4;
	} else delay--;

	tileY = (xDir == -1 ? 0 : 1);
	tileX += 0.1f;
	if(tileX > 4) tileX = 0;

}

WraithProjectile::~WraithProjectile() {}
