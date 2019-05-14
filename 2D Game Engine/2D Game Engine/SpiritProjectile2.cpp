#include "SpiritProjectile2.h"

#include "Particle.h"

SpiritProjectile2::SpiritProjectile2(float x, float y, float init_vX, float init_vY, int init_xDir, int init_yDir,
	GameObject * init_spawner, GameObject * init_spawn)  : SpiritProjectile(x, y, init_vX, init_vY, init_xDir, 
		init_yDir, init_spawner, init_spawn) {
	
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

	damage = 3;

	SDL_DestroyTexture(texture);
	texture = TextureManager::LoadTexture(Game::renderer, "assets/Enemies/Wraith.png");

}

SpiritProjectile2::~SpiritProjectile2() {}

void SpiritProjectile2::Update(LevelManager * game) {

	SpiritProjectile::Update(game);

	tileY = (vX <= -1 ? 0 : 1);
	tileX += 0.1f;
	if(tileX > 4) tileX = 0;
	
}
