#include "Player.h"

#include "Game.h"
#include "Fireball.h"
#include "Smoke.h"

Player::Player(float x, float y) : GameObject("assets/Player.png", x, y, 21, 36, 3) {

	vX = 0;
	vY = 0;

	collidable = true;

	health = 10;
	damageable = false;
	
}

Player::~Player() {

	

}

void Player::Update(LevelManager * game) {

	if(Game::event.type == SDL_KEYDOWN) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_SPACE:
				attack = true;
				break;

			case SDLK_w:
				if(grounded) vY = -jumpPower;
				break;

			case SDLK_a:
				left = true;
				right = false;
				dir = -1;
				tileY = 1;
				break;

			case SDLK_d:
				right = true;
				left = false;
				dir = 1;
				tileY = 0;
				break; 
							
		}

	}
	if(Game::event.type == SDL_KEYUP) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_SPACE:
				attack = false;
				break;
			
			case SDLK_a:
				left = false;
				break;

			case SDLK_d:
				right = false;
				break;
							   
		}

	}

	if(attack && shot == 0) {
		if(!attackLock && manaFatigue >= 2) {
			game->AddObject(new Fireball(dir == -1 ? x : x + width, y + 14 * scale, vX + 10 * dir, vY, dir, 0, this));
			shot = shotDelay;
			manaFatigue -= 2;
		} else if(smokeDelay == 0) {
			game->AddObject(new Smoke(dir == -1 ? x - 2 : x + width, y + 14 * scale));
			smokeDelay = 5;
		}
	}

	if(smokeDelay != 0) smokeDelay--;

	if(shot > 0) shot--;

	if(!attack && manaFatigue < 10) manaFatigue += .08f;

	if(!attack && left) {
		if(vX > -maxSpeed) vX -= acceleration;
		tileX += .17f;
	}
	if(!attack && right) {
		if(vX < maxSpeed) vX += acceleration;
		tileX += .17f;
	}

	if(attack || (!left && !right)) {
		vX /= decceleration;
		tileX = attack ? 9 : 0;
	}
			
	vY += .7f;

	if(tileX > 9) tileX = 1;
					
}

float Player::GetManaFatigue() {

	return manaFatigue;

}
