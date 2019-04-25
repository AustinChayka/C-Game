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

Particle::~Particle() {
	
}

void Particle::UpdateObject(LevelManager * game) {

	Update(game);
	
	vY += grav;

	x += vX;
	y += vY;

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

void Particle::Update(LevelManager * game) {

	if(shrink) if(width > 1) {
		width -= shrinkSpeed;
		height -= shrinkSpeed;
	} else dead = true;

	if(fade) {
		if(alpha > 0) alpha - fadeSpeed > 0 ? alpha -= fadeSpeed : alpha = 0;
		else dead = true;
	}

	if(img) {
		SDL_SetTextureAlphaMod(texture, alpha);
	}
			
}

void Particle::RenderObject() {

	if(img) {
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
	} else {
		SDL_SetRenderDrawColor(Game::renderer, (Uint8) red, (Uint8) green, (Uint8) blue, (Uint8) alpha);
		SDL_RenderFillRect(Game::renderer, &destRect);
	}

}

void Particle::SetFadeSpeed(float s) {

	fadeSpeed = s;

}

void Particle::SetShrinkSpeed(float s) {

	shrinkSpeed = s;

}

void Particle::SetColor(int r, int g, int b) {

	red = r;
	green = g;
	blue = b;

}
