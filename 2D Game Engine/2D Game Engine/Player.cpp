#include "Player.h"

#include "Game.h"
#include "Smoke.h"
#include "Item.h"
#include "SoftPlatform.h"
#include "UseableItem.h"
#include "ItemObject.h"

Player::Player(float x, float y) : Enemy("assets/Enemies/Player.png", x, y, 21, 36, 3, 20) {

	vX = 0;
	vY = 0;

	collidable = true;
	moveable = true;
	solid = true;
	
	decceleration = 1.15f;
	grav = .55f;

	items = new std::vector<Item *>;

}

Player::~Player() {

	

}

void Player::Update(LevelManager * game) {

	Enemy::Update(game);

	for(auto item : *items) item->Update(game, this);

	if(Game::inputManager->IsPressed(InputManager::dash) && manaFatigue >= 5) {
		dash = 6;
		damageable = false;
		collidable = false;
		manaFatigue -= 5;
		grav = 0;
	}

	if(Game::inputManager->IsDown(InputManager::left)) {
		dir = -1;
		tileY = 1;
	} else if(Game::inputManager->IsDown(InputManager::right)) {
		dir = 1;
		tileY = 0;
	}

	if(Game::inputManager->IsDown(InputManager::croutch) && 
		manaFatigue > .15f) {
		if(Game::inputManager->IsPressed(InputManager::croutch)) {
			y += 24 * 3;
		}
		height = 12 * 3;
		width = 7 * 3;
		manaFatigue -= .15f;
	} else {
		if(height != 36 * 3) {
			y -= 24 * 3;
		}
		height = 36 * 3;
		width = 21 * 3;
	}

	if(dash == 0 && Game::inputManager->IsDown(InputManager::shoot) && shot == 0) {

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

	if(!Game::inputManager->IsDown(InputManager::shoot)  && !Game::inputManager->IsDown(InputManager::croutch)
		&& manaFatigue < maxFatigue) manaFatigue += manaRegen;
	
	if(grounded) jumps = 0;

	if(Game::inputManager->IsPressed(InputManager::jump) && jumps < maxJumps) {
		vY = -jumpPower;
		y += -jumpPower;
		jumps++;
	}

	if(dash == 0 && !Game::inputManager->IsDown(InputManager::shoot) && Game::inputManager->IsDown(InputManager::left)) {
		decceleration = 1;
		if(vX > -maxSpeed) vX -= acceleration;
		tileX += .17f;
	}
	else if(dash == 0 && !Game::inputManager->IsDown(InputManager::shoot) && Game::inputManager->IsDown(InputManager::right)) {
		decceleration = 1;
		if(vX < maxSpeed) vX += acceleration;
		tileX += .17f;
	}

	if(dash == 0 && (Game::inputManager->IsDown(InputManager::shoot) || 
		(!Game::inputManager->IsDown(InputManager::left) && !Game::inputManager->IsDown(InputManager::right)))) {
		decceleration = 1.15f;
		tileX = Game::inputManager->IsDown(InputManager::shoot) ? 9 : 0;
	}

	if(tileX > 9) tileX = 1;
					
}

void Player::RenderObject(int l) {

	Enemy::RenderObject(l);
	RenderItems(l);

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

	if(ImmuneTo(go)) return;
	
	int newDamage = d;
	for(auto item : *items) {
		item->OnDamageTaken(game, go, this);
		newDamage -= item->OverrideDamageTotal(newDamage, go, this);
	}

	GameObject::DealDamage(newDamage, game, go);
	
}

void Player::AddItem(Item * item, LevelManager * game) {

	if(dynamic_cast<UseableItem *>(item) != nullptr) {
		useItem = (UseableItem *) (item);
		for(int i = 0; i < items->size(); i++) if(dynamic_cast<UseableItem *>(items->at(i)) != nullptr) {
			game->AddObject(new ItemObject(GetXCenter() - 12, y + height - 24, items->at(i)));
			items->erase(items->begin() + i);
		}
	}

	item->OnPickup(game, this);
	items->push_back(item);

}

std::vector<Item*>* Player::GetItems() {

	return items;

}

void Player::DamageDelt(LevelManager * game, GameObject * go, bool crit) {

	for(auto item : *items) item->OnDamageDelt(game, this, go, crit);

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

void Player::SetShotDelay(int d) {

	shotDelay = d;

}

int Player::GetShotDelay() {

	return shotDelay;

}

void Player::SetShotCost(float c) {

	shotCost = c;

}

float Player::GetShotCost() {

	return shotCost;

}

bool Player::OverrideStatus(Status * s) {

	return !damageable;

}

int Player::GetCritChance() {
	
	return critChance;

}

float Player::GetCritValue() {

	return critMultiplier;

}

void Player::SetCritChance(int c) {

	critChance = c;

}

void Player::SetCritValue(float v) {

	critMultiplier = v;

}

int Player::GetLuck() {

	return luck;

}

void Player::SetLuck(int l) {

	luck = l;

}

int Player::GetGold() {

	return gold;

}

void Player::AddGold(int g) {

	gold += g;

}

void Player::SetGold(int g) {

	gold = g;

}
