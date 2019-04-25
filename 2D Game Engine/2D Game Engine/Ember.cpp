#include "Ember.h"

#include "Fire.h"

Ember::Ember(float init_x, float init_y, float init_vX, float init_vY, GameObject * init_spawner) : Particle(init_x, init_y, 5, 5, 255, 128, 0, 200) {

	vX = init_vX;
	vY = init_vY;

	moveable = false;
	collidable = true;

	spawner = init_spawner;

	grav = .3f;

}

Ember::~Ember() {}

void Ember::OnCollision(GameObject * go, LevelManager * game) {

	if(go == spawner || !go->IsSolid()) return;

	dead = true;

	game->AddObject(new Fire(x, y - 10, (int) (2.5 * width / 5), spawner));

}

void Ember::UpdateObject(LevelManager * game) {
	
	Update(game);

	vY += grav;

	x += vX;
	y += vY;

	UpdateCollisions(game);
	Collide();

	if(red > 255) red = 255;
	if(green > 255) green = 255;
	if(blue > 255) blue = 255;
	if(alpha > 255) alpha = 255;
	if(red < 0) red = 0;
	if(green < 0) green = 0;
	if(blue < 0) blue = 0;
	if(alpha < 0) alpha = 0;

	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(width * Game::camera->GetScale());
	destRect.h = (int)(height * Game::camera->GetScale());

}
