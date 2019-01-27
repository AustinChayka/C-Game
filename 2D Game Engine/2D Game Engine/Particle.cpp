#include "Particle.h"


Particle::Particle(float init_x, float init_y, float init_width, float init_height, 
	float r, float g, float b, float a) : GameObject(nullptr, init_x, init_y, init_width, init_height) {

	red = r;
	green = g;
	blue = b;
	alpha = a;

}

Particle::~Particle() {}

void Particle::Update(LevelManager * game) {

	if(shrink && width > 1) {
		width -= .1f;
		height -= .1f;
	} else dead = true;

	if(fade && alpha > 0) alpha -= .5f;
	else dead = true;
	
}

void Particle::RenderObject() {
	
	SDL_SetRenderDrawColor(Game::renderer, (Uint8)red, (Uint8)green, (Uint8)blue, (Uint8)alpha);
	for(int i = 0; i < height; i++) for(int j = 0; j < width; j++) 
		SDL_RenderDrawPoint(Game::renderer, (x + j - Game::camera->GetX()) * Game::camera->GetScale(), 
			(y + i - Game::camera->GetY()) * Game::camera->GetScale());

}
