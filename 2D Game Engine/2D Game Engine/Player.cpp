#include "Player.h"

#include "Game.h"
#include "Projectile.h"

Player::Player(float x, float y) : GameObject("assets/Player.png", x, y, 21, 36, 3) {

	vX = 0;
	vY = 0;

	collidable = true;
	
}

Player::~Player() {

	

}

void Player::Update(LevelManager * game) {

	if(Game::event.type == SDL_KEYDOWN) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_w:
				if(grounded) vY = -jumpPower;
				break;

			case SDLK_a:
				left = true;
				dir = -1;
				break;

			case SDLK_d:
				right = true;
				dir = 1;
				break; 
			
			case SDLK_SPACE:
				if(shot == 0) {
					game->AddObject(new Projectile(GetXCenter(), GetYCenter(), vX + 10 * dir, vY, dir, 0, this));
					shot = shotDelay;
				}
				break;
				
		}

	}
	if(Game::event.type == SDL_KEYUP) {

		switch(Game::event.key.keysym.sym) {
			
			case SDLK_a:
				left = false;
				break;

			case SDLK_d:
				right = false;
				break;


		}

	}

	if(shot > 0) shot--;

	if(left) {
		if(vX > -maxSpeed) vX -= acceleration;
		tileY = 1;
		tileX += .17f;
	}
	if(right) {
		if(vX < maxSpeed) vX += acceleration;
		tileY = 0;
		tileX += .17f;
	}

	if(!left && !right) {
		vX /= decceleration;
		tileX = 0;
	}
			
	vY += .7f;

	if(tileX > 9) tileX = 1;
				
}
