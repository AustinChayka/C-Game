#include "GameObject.h"

#include <cmath>
#include "Particle.h"
#include "Room.h"

GameObject::GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height) {

	if(textureSheet != nullptr) texture = TextureManager::LoadTexture(Game::renderer, textureSheet);

	x = init_x;
	y = init_y;
	spriteWidth = init_width;
	spriteHeight = init_height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	width = (float)init_width;
	height = (float)init_height;

	scale = 1;
	
}

GameObject::GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
	float init_scale) {

	if(textureSheet != nullptr) texture = TextureManager::LoadTexture(Game::renderer, textureSheet);

	x = init_x;
	y = init_y;
	spriteWidth = init_width;
	spriteHeight = init_height;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = spriteWidth;
	srcRect.h = spriteHeight;

	width = init_width * init_scale;
	height = init_height * init_scale;

	scale = init_scale;

}

GameObject::~GameObject() {

	if(texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	
}

void GameObject::UpdateCollisions(LevelManager * game) {

	if(!collidable) return;

	grounded = pushedUp = pushedDown = pushedLeft = pushedRight = false;
	collisions.clear();

	for(auto go : *game->GetObjects()) if(this->CollidesWith(go)) {

		OnCollision(go, game);

		if(!moveable || !go->IsSolid()) continue;

		if(!go->IsMoveable()) {
			if(!go->OverrideCollision(this)) collisions.push_back(go);
		} else if(!OverrideCollision(go)) collisions.push_back(go);
		
		if(GetXOverlap(go) < GetYOverlap(go)) {
			if(GetXCenter() > go->GetXCenter()) {
				pushedLeft = true;
			} else {
				pushedRight = true;
			}
		} else {
			if(GetYCenter() > go->GetYCenter()) {
				pushedDown = true;
			} else {
				pushedUp = true;
				grounded = true;
			}
		}

	}

}

void GameObject::Collide() {

	for(auto go : collisions) {

		if(GetXOverlap(go) < GetYOverlap(go)) {
			if(GetXCenter() > go->GetXCenter()) {
				if(go->IsMoveable() && !go->IsPushedLeft()) go->SetX(go->GetX() + vX);
				if(GetXOverlap(go) > 0) {
					x += GetXOverlap(go);
					vX = vX > 0 ? vX : 0;
				}
			} else {
				if(go->IsMoveable() && !go->IsPushedRight()) go->SetX(go->GetX() + vX);
				if(GetXOverlap(go) > 0) {
					x -= GetXOverlap(go);
					vX = vX < 0 ? vX : 0;
				}
			}
		} else {
			if(GetYCenter() > go->GetYCenter()) {
				if(go->IsMoveable() && !go->IsPushedDown()) go->SetY(go->GetY() + vY);
				if(GetYOverlap(go) > 0) {
					y += GetYOverlap(go);
					vY = vY > 0 ? vY : 0;
				}
			} else {
				if(go->IsMoveable() && !go->IsPushedUp()) go->SetY(go->GetY() + vY);
				x += go->GetVX();
				if(GetYOverlap(go) > 0) {
					y -= GetYOverlap(go);
					vY = vY < 0 ? vY : 0;
				}
			}
		}

	}

}

void GameObject::UpdateObject(LevelManager * game) {

	Update(game);

	if(damageDelay > 0) damageDelay--;
	if(damageFlash > 0) damageFlash--;
	else if(damageFlash == 0) {
		SDL_SetTextureColorMod(texture, 255, 255, 255);
		damageFlash--;
	}

	vY += grav;
	if(grounded) vX /= decceleration;
	
	x += vX;
	y += vY;

	UpdateCollisions(game);
	Collide();

	visible = false;
	for(auto r : *game->GetRooms())
		if(x < r->GetX() + r->GetWidth()
			&& x + width > r->GetX()
			&& y < r->GetY() + r->GetHeight()
			&& y + height > r->GetY() && r->IsRevealed()) visible = true;
	
	srcRect.x = (int)tileX * spriteWidth;
	srcRect.y = (int)tileY * spriteHeight;
	
	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(width * Game::camera->GetScale());
	destRect.h = (int)(height * Game::camera->GetScale());

}

void GameObject::RenderObject() {

	if(!visible) return;

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}

bool GameObject::CollidesWith(GameObject * go) {

	if(this == go) return false;

	return x + (vX > 0 ? -vX : 0) <= go->GetX() + go->GetWidth() + (go->GetVX() < 0 ? -go->GetVX() : 0)
		&& x + width + (vX < 0 ? -vX : 0) >= go->GetX() + (go->GetVX() > 0 ? -go->GetVX() : 0)
		&& y + (vY > 0 ? -vY : 0) <= go->GetY() + go->GetHeight() + (go->GetVY() < 0 ? -go->GetVY() : 0) 
		&& y + height + (vY < 0 ? -vY : 0) >= go->GetY() + (go->GetVY() > 0 ? -go->GetVY() : 0);

}

float GameObject::DistanceToSquared(GameObject * go) {

	return pow(x - go->GetX(), 2) + pow(y - go->GetY(), 2);

}

bool GameObject::IsSolid() {

	return solid;

}

bool GameObject::OnScreen() {

	return x < Game::camera->GetX() + Game::camera->GetWidth()
		&& x + width > Game::camera->GetX()
		&& y < Game::camera->GetY() + Game::camera->GetHeight()
		&& y + height > Game::camera->GetY();

}

float GameObject::GetX() {

	return x;

}

float GameObject::GetY() {

	return y;

}

float GameObject::GetVX() {

	return vX;

}

float GameObject::GetVY() {

	return vY;

}

int GameObject::GetWidth() {

	return (int)width;

}

int GameObject::GetHeight() {

	return (int)height;

}

void GameObject::SetCollidable(bool c) {

	collidable = c;

}

void GameObject::SetMoveable(bool m) {

	moveable = m;

}

void GameObject::SetSolid(bool s) {

	solid = s;

}

int GameObject::GetRenderLayer() {

	return renderLayer;

}

SDL_Rect * GameObject::GetSrcRect() {

	return &srcRect;

}

bool GameObject::IsPushedUp() {

	return pushedUp;

}

bool GameObject::IsPushedDown() {

	return pushedDown;

}

bool GameObject::IsPushedLeft() {

	return pushedLeft;

}

bool GameObject::IsPushedRight() {

	return pushedRight;

}

bool GameObject::OverrideCollision(GameObject * go) {

	return false;

}

void GameObject::SetGrav(float g) {

	grav = g;

}

void GameObject::SetDecceleration(float d) {

	decceleration = d;

}

float GameObject::GetGrav() {

	return grav;

}

float GameObject::GetDecceleration() {

	return decceleration;

}

SDL_Texture * GameObject::GetTexture() {

	return texture;

}

void GameObject::OnDeath(LevelManager * game, GameObject * go) {

	if(dynamic_cast<Player *>(go) != nullptr && dynamic_cast<Enemy *>(this) != nullptr) ((Player *) go)->OnKill(game, this);

}

float GameObject::GetXCenter() {

	return x + width / 2;

}

float GameObject::GetYCenter() {

	return y + height / 2;

}

bool GameObject::IsDead() {

	return dead;

}

bool GameObject::IsMoveable() {

	return moveable;

}

void GameObject::SetVX(float new_vX) {

	vX = new_vX;

}

void GameObject::SetVY(float new_vY) {

	vY = new_vY;

}

void GameObject::SetX(float new_x) {

	x = new_x;

}

void GameObject::SetY(float new_y) {

	y = new_y;

}

int GameObject::GetHealth() {

	return health;

}

int GameObject::GetMaxHealth() {

	return maxHealth;

}

void GameObject::SetMaxHealth(int h) {

	maxHealth = h;
	if(maxHealth < health) health = maxHealth;

}

bool GameObject::IsDamagable() {

	return damageable;

}

void GameObject::SetDamagable(bool d) {

	damageable = d;

}

bool GameObject::IsAt(float xTarget, float yTarget) {

	return xTarget <= x + width && xTarget >= x &&
		yTarget <= y + height && yTarget >= y;

}

void GameObject::DealDamage(int d, LevelManager * game, GameObject * go) {

	if(!damageable || damageDelay > 0 || d == 0 || health <= 0) return;
	health -= d;
	if(health > 0) {
		damageDelay = 20;
		damageFlash = 10;
		SDL_SetTextureColorMod(texture, 255, 80, 80);
	}
	if(go != nullptr && dynamic_cast<Player *>(go) != nullptr) ((Player *) go)->DamageDelt(game, this);

	if(health <= 0) {
		OnDeath(game, go);
		dead = true;
	}

}

void GameObject::DealDamage(int d, LevelManager * game) {

	health -= d;
	if(health > 0) {
		damageDelay = 20;
		damageFlash = 10;
		SDL_SetTextureColorMod(texture, 255, 80, 80);
	}

	if(health <= 0) {
		OnDeath(game, nullptr);
		dead = true;
	}

}

void GameObject::Heal(int h) {

	if(!damageable) return;

	if(maxHealth > health + h) health += h;
	else health = maxHealth;

}

float GameObject::GetXOverlap(GameObject * go) {

	if(x > go->GetX()) return go->GetX() + go->GetWidth() - x;
	else return x + width - go->GetX();

}

float GameObject::GetYOverlap(GameObject * go) {

	if(y > go->GetY()) return go->GetY() + go->GetHeight() - y;
	else return y + height - go->GetY();

}
