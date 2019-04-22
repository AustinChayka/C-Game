#include "Corpse.h"

#include "ImageTile.h"

Corpse::Corpse(const char * filepath, float x, float y, int width, int height, int init_tileX, int init_tileY, float scale) : 
	GameObject(filepath, x, y, width, height, scale) {

	path = filepath;
	tileX = init_tileX;
	tileY = init_tileY;
	img_width = width;
	img_height = height;

	collidable = true;
	solid = false;
	moveable = true;

	grav = .4f;

}

Corpse::~Corpse() {}

void Corpse::Update(LevelManager * game) {

	if(delay > 0) delay--;
	else {

		if(grounded) {
			dead = true;
			ImageTile * tile = new ImageTile(path, x, y, img_width, img_height, tileX, tileY, scale, renderLayer);
			SDL_SetTextureColorMod(tile->GetTexture(), 200, 200, 200);
			game->AddTile(tile);
		}

	}

}

bool Corpse::OverrideCollision(GameObject * go) {

	return go->IsMoveable();

}
