#include "Particle.h"

Particle::Particle(float init_x, float init_y, float init_width, float init_height, 
	float r, float g, float b, float a) : GameObject(nullptr, init_x, init_y, init_width, init_height) {
	
	red = r;
	green = g;
	blue = b;
	alpha = a;

	moveable = false;
	collidable = false;
	solid = false;

	img = false;

	renderLayer = 2;

}

Particle::Particle(const char * filepath, float init_x, float init_y, float init_width, float init_height, 
	int init_tileX, int init_tileY, float scale) : GameObject(filepath, init_x, init_y, init_width, init_height, scale) {

	tileX = init_tileX;
	tileY = init_tileY;
		
	moveable = false;
	collidable = false;
	solid = false;

	img = true; 

	alpha = 255;

	shrink = false;
	
}

Particle::~Particle() {}

void Particle::Update(LevelManager * game) {

	if(shrink) if(width > 1) {
		width -= shrinkSpeed;
		height -= shrinkSpeed;
	} else dead = true;

	if(fade) if(alpha > 0) alpha - fadeSpeed > 0 ? alpha -= fadeSpeed : alpha = 0;
	else dead = true;

	if(img) {
		SDL_SetTextureAlphaMod(texture, alpha);
		destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
		destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
		destRect.w = (int)(width * Game::camera->GetScale());
		destRect.h = (int)(height * Game::camera->GetScale());
	}
			
}

void Particle::RenderObject() {

	if(img) {
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
		return;
	}
	
	SDL_SetRenderDrawColor(Game::renderer, (Uint8)red, (Uint8)green, (Uint8)blue, (Uint8)alpha);
	for(int i = 0; i < height; i++) for(int j = 0; j < width; j++) 
		SDL_RenderDrawPoint(Game::renderer, (x + j - Game::camera->GetX()) * Game::camera->GetScale(), 
			(y + i - Game::camera->GetY()) * Game::camera->GetScale());

}

void Particle::SetFadeSpeed(float s) {

	fadeSpeed = s;

}

void Particle::SetShrinkSpeed(float s) {

	shrinkSpeed = s;

}
