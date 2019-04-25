#include "Player.h"

#include "Game.h"
#include "Fireball.h"
#include "Smoke.h"
#include "Item.h"
#include "SoftPlatform.h"
#include "UseableItem.h"

#include "BabyMaw.h"

Player::Player(float x, float y) : Enemy("assets/Enemies/Player.png", x, y, 21, 36, 3, 10) {

	vX = 0;
	vY = 0;

	collidable = true;
	moveable = true;
	solid = true;
	
	decceleration = 1.15f;
	grav = .55f;

	items = new std::vector<Item *>;

	AddItem(new BabyMaw(), nullptr);
	
}

Player::~Player() {

	

}

void Player::Update(LevelManager * game) {

	Enemy::Update(game);

	for(auto item : *items) item->Update(game, this);
	
	lastJump = jump;

	if(Game::event.type == SDL_KEYDOWN && dash == 0) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_SPACE:
				attack = true;
				break;

			case SDLK_w:
				jump = true;
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
				if(dash == 0 && manaFatigue >= 5) {
					dash = 6;
					damageable = false;
					collidable = false;
					manaFatigue -= 5;
					grav = 0;
				}
				break;

			case SDLK_s:
				down = true;
				break;
							
		}

	}
	if(Game::event.type == SDL_KEYUP) {

		switch(Game::event.key.keysym.sym) {

			case SDLK_SPACE:
				attack = false;
				break;

			case SDLK_w:
				jump = false;
				break;
			
			case SDLK_a:
				left = false;
				break;

			case SDLK_d:
				right = false;
				break;

			case SDLK_s:
				down = false;
				break;
							   
		}

	}

	if(dash == 0 && attack && shot == 0) {

		if(!attackLock && manaFatigue >= shotCost) {

			Projectile * p = new Projectile("assets/Other/DefaultProjectile.png", dir == -1 ? x : x + width, y + 14 * scale, vX + 10 * dir, vY, dir, 0, this);

			for(auto item : *items) if(item->OverrideDefaultProjectile(this, p)) break;
			for(auto item : *items) item->OnShotFired(game, this, p);

			game->AddObject(p);
			shot = shotDelay;
			manaFatigue -= shotCost;

		} else if(smokeDelay == 0) {

			game->AddObject(new Smoke(dir == -1 ? x - 2 : x + width, y + 14 * scale));
			smokeDelay = 5;

		}

	}

	if(dash > 0) {
		Particle * p = new Particle("assets/Enemies/Player.png", x, y, 21, 36, (int)((dash / 6.0f) * 9), tileY, 3);
		p->SetFadeSpeed(8);
		game->AddObject(p);
		for(auto go : *(game->GetObjects())) if(go->IsSolid() && !go->IsMoveable() && dynamic_cast<SoftPlatform *>(go) == nullptr &&
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

	if(smokeDelay > 0) smokeDelay--;

	if(shot > 0) shot--;

	if(!attack && manaFatigue < maxFatigue) manaFatigue += manaRegen;
	
	if(grounded) jumps = 0;

	if(jump && !lastJump && jumps < maxJumps) {
		vY = -jumpPower;
		y += -jumpPower;
		jumps++;
	}

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

	std::cout << jumps << std::endl;
					
}

void Player::RenderObject() {

	Enemy::RenderObject();

}

void Player::RenderItems(int layer) {

	for(auto item : *items) if(item->GetLayer() == layer) item->Render();

}

void Player::SetManaFatigue(float m) {

	maxFatigue = m;

}

float Player::GetManaFatigue() {

	return manaFatigue;

}

float Player::GetMaxManaFatigue() {

	return maxFatigue;

}

void Player::SetManaRegen(float r) {

	manaRegen = r;

}

float Player::GetManaRegen() {

	return manaRegen;

}

void Player::DealDamage(int d, LevelManager * game, GameObject * go) {

	if(damageDelay > 0) return;
	
	int newDamage = d;
	for(auto item : *items) {
		item->OnDamageTaken(game, go, this);
		newDamage -= item->OverrideDamageTotal(newDamage, go, this);
	}

	if(newDamage <= 0) {
		damageDelay = 20;
		return;
	}

	GameObject::DealDamage(newDamage, game, go);
	
}

void Player::AddItem(Item * item, LevelManager * game) {

	if(dynamic_cast<UseableItem *>(item) != nullptr) {
		useItem = (UseableItem *) (item);
		for(int i = 0; i < items->size(); i++) if(dynamic_cast<UseableItem *>(items->at(i)) != nullptr) {
			delete items->at(i);
			items->erase(items->begin() + i);
		}
	}

	item->OnPickup(game, this);
	items->push_back(item);

}

std::vector<Item*>* Player::GetItems() {

	return items;

}

void Player::DamageDelt(LevelManager * game, GameObject * go) {

	for(auto item : *items) item->OnDamageDelt(game, this, go);

}

void Player::UpdateProjectile(LevelManager * game, Projectile * p) {

	for(auto item : *items) item->UpdateProjectile(game, this, p);

}

void Player::OnKill(LevelManager * game, GameObject * go) {

	for(auto item : *items) item->OnKill(game, this, go);

}

int Player::GetDir() {

	return dir;

}

bool Player::DownPressed() {

	return down;

}

UseableItem * Player::GetUseItem() {

	return useItem;

}

void Player::SetMaxJumps(int j) {

	maxJumps = j;

}

int Player::GetMaxJumps() {

	return maxJumps;

}

void Player::SetMaxSpeed(float s) {

	maxSpeed = s;

}

float Player::GetMaxSpeed() {

	return maxSpeed;

}

void Player::SetAcceleration(float a) {

	acceleration = a;

}

float Player::GetAcceleration() {

	return acceleration;

}

bool Player::OverrideStatus(Status * s) {

	return !damageable;

}
