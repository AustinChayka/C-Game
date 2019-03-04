#include "Player.h"

#include "Game.h"
#include "Fireball.h"
#include "Smoke.h"
#include "Item.h"

Player::Player(float x, float y) : GameObject("assets/Player.png", x, y, 21, 36, 3) {

	vX = 0;
	vY = 0;

	collidable = true;
	moveable = true;
	solid = true;

	maxHealth = health = 10;
	damageable = true;

	decceleration = 1.15f;
	grav = .55f;

	items = new std::vector<Item *>;
	
}

Player::~Player() {

	

}

void Player::Update(LevelManager * game) {

	for(auto item : *items) item->Update(game, this);
	
	if(Game::event.type == SDL_KEYDOWN && dash == 0) {

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

			case SDLK_LSHIFT:
				if(dash == 0 && manaFatigue >= 6) {
					dash = 6;
					damageable = false;
					collidable = false;
					manaFatigue -= 5;
					grav = 0;
				}
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

	if(dash == 0 && attack && shot == 0) {

		if(!attackLock && manaFatigue >= 2) {

			for(auto item : *items) item->OnShotFired(game, this);

			game->AddObject(new Fireball(dir == -1 ? x : x + width, y + 14 * scale, vX + 10 * dir, vY, dir, 0, this));
			shot = shotDelay;
			manaFatigue -= 2;

		} else if(smokeDelay == 0) {

			game->AddObject(new Smoke(dir == -1 ? x - 2 : x + width, y + 14 * scale));
			smokeDelay = 5;

		}

	}

	if(dash > 0) {
		Particle * p = new Particle("assets/Player.png", x, y, 21, 36, (int)((dash / 6.0f) * 9), tileY, 3);
		p->SetFadeSpeed(8);
		game->AddObject(p);
		for(auto go : *(game->GetObjects())) if(go->IsSolid() && !go->IsMoveable() &&
			x + width + (dir == 1 ? 50 : 0) > go->GetX() && x + (dir == 1 ? 0 : -50) < go->GetX() + go->GetWidth() &&
			y + height > go->GetY() && y < go->GetY() + go->GetHeight() && GetXOverlap(go) < GetYOverlap(go)) {
				x = (dir == 1 ? go->GetX() - width : go->GetX() + go->GetWidth());
				dash = 0;
				return;
			}
		if(dash != 0) {
			x += (dir == 1 ? 50 : -50);
			dash--;
		} else vX = maxSpeed * (dir == 1 ? 1.5f : -1.5f);
	} else {
		damageable = true;
		collidable = true;
		grav = .55f;
	}

	if(smokeDelay != 0) smokeDelay--;

	if(shot > 0) shot--;

	if(!attack && manaFatigue < 10) manaFatigue += .08f;

	if(dash == 0 && !attack && left) {
		decceleration = 1;
		if(vX > -maxSpeed) vX -= acceleration;
		tileX += .17f;
	}
	if(dash == 0 && !attack && right) {
		decceleration = 1;
		if(vX < maxSpeed) vX += acceleration;
		tileX += .17f;
	}

	if(dash == 0 && (attack || (!left && !right))) {
		decceleration = 1.15f;
		tileX = attack ? 9 : 0;
	}

	if(tileX > 9) tileX = 1;
					
}

void Player::RenderObject() {

	GameObject::RenderObject();
	for(auto item : *items) item->Render();

}

float Player::GetManaFatigue() {

	return manaFatigue;

}

void Player::DealDamage(int d, LevelManager * game, GameObject * go) {

	if(damageDelay == 0) for(auto item : *items) item->OnDamageTaken(game, go, this);

	GameObject::DealDamage(d, game, go);
	
}

void Player::AddItem(Item * item, LevelManager * game) {

	item->OnPickup(game, this);
	items->push_back(item);

}

std::vector<Item*>* Player::GetItems() {

	return items;

}

void Player::DamageDelt(LevelManager * game, GameObject * go) {

	for(auto item : *items) item->OnDamageDelt(game, this, go);

}
