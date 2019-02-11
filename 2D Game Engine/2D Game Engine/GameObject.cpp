#include "GameObject.h"
#include <cmath>
#include "Particle.h"

#include "Debris.h"

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

	SDL_DestroyTexture(texture);
	texture = nullptr;
	
}

void GameObject::UpdateObject(LevelManager * game) {
	
	Update(game);

	if(damageable && health <= 0) {
		OnDeath(game);
		dead = true;
	}

	if(damageDelay < 20) damageDelay++;
	
	x += vX;
	y += vY;
	
	grounded = false;
	if(collidable) for(auto go : game->GetObjects()) if(this->CollidesWith(go)) {
		go->OnCollision(this, game);
		if(solid && go->IsMoveable()) go->LockCollision(this);
	}

	srcRect.x = (int)tileX * spriteWidth;
	srcRect.y = (int)tileY * spriteHeight;
	
	destRect.x = (int)((x - Game::camera->GetX()) * Game::camera->GetScale());
	destRect.y = (int)((y - Game::camera->GetY()) * Game::camera->GetScale());
	destRect.w = (int)(width * Game::camera->GetScale());
	destRect.h = (int)(height * Game::camera->GetScale());

}

void GameObject::RenderObject() {

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}

bool GameObject::CollidesWith(GameObject * go) {

	if(this == go) return false;

	return x < go->GetX() + go->GetWidth()
		&& x + width > go->GetX()
		&& y < go->GetY() + go->GetHeight()
		&& y + height > go->GetY();

}

float GameObject::DistanceToSquared(GameObject * go) {

	return pow(x - go->GetX(), 2) + pow(y - go->GetY(), 2);

}

bool GameObject::IsSolid() {

	return solid;

}

bool GameObject::HasLineOfSight(GameObject * go, LevelManager * game) {

	if(!OnScreen()) return false;

	float x1 = GetXCenter(), x2 = go->GetXCenter(), y1 = GetYCenter(), y2 = go->GetYCenter();

	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
	if(steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if(x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);

	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;

	const int maxX = (int)x2;

	bool clear = true;

	for(int x=(int)x1; x<maxX; x++) {

		if(steep) {
			for(auto goAt : game->GetObjects()) if(goAt != this && goAt != go && dynamic_cast<Particle*>(goAt) == nullptr) clear &= !goAt->IsAt(y, x);
		} else {
			for(auto goAt : game->GetObjects()) if(goAt != this && goAt != go && dynamic_cast<Particle*>(goAt) == nullptr) clear &= !goAt->IsAt(x, y);
		}

		error -= dy;
		if(error < 0)
		{
			y += ystep;
			error += dx;
		}
	}

	return clear;

}

void GameObject::DrawLineOfSight(GameObject * go, LevelManager * game) {

	if(!OnScreen()) return;
	
	float x1 = GetXCenter(), x2 = go->GetXCenter(), y1 = GetYCenter(), y2 = go->GetYCenter();

	const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));

	if(steep)
	{
		std::swap(x1, y1);
		std::swap(x2, y2);
	}

	if(x1 > x2)
	{
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);

	float error = dx / 2.0f;
	const int ystep = (y1 < y2) ? 1 : -1;
	int y = (int)y1;

	const int maxX = (int)x2;
	
	bool clear = true;

	for(int x=(int)x1; x<maxX; x++)
	{

		if(steep)
		{
			for(auto goAt : game->GetObjects()) if(goAt != this && goAt != go && dynamic_cast<Particle*>(goAt) == nullptr) clear &= !goAt->IsAt(y, x);
			if(clear) {
				SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
				SDL_RenderDrawPoint(Game::renderer, y - Game::camera->GetX(), x - Game::camera->GetY());
			}
		}
		else
		{
			for(auto goAt : game->GetObjects()) if(goAt != this && goAt != go && dynamic_cast<Particle*>(goAt) == nullptr) clear &= !goAt->IsAt(x, y);
			if(clear) {
				SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
				SDL_RenderDrawPoint(Game::renderer, x - Game::camera->GetX(), y - Game::camera->GetY());
			}
		}

		error -= dy;
		if(error < 0)
		{
			y += ystep;
			error += dx;
		}
	}

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

void GameObject::LockX(GameObject * go) {

	if(x > go->GetX()) x = go->GetX() + go->GetWidth();
	else x = go->GetX() - width;

	vX = 0;

}

void GameObject::LockY(GameObject * go) {

	if(y > go->GetY()) y = go->GetY() + go->GetHeight();
	else {
		y = go->GetY() - height;
		grounded = true;
	}

	vY = 0;

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

void GameObject::OnDeath(LevelManager * game) {}

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

bool GameObject::IsAt(float xTarget, float yTarget) {

	return xTarget <= x + width && xTarget >= x &&
		yTarget <= y + height && yTarget >= y;

}

void GameObject::DealDamage(int d) {

	if(!damageable || damageDelay != 20) return;
	health -= d;
	damageDelay = 0;

}

void GameObject::LockCollision(GameObject * go) {

	int collisionWall = GetCollisionWall(go);

	if(collisionWall == Wall::RIGHT || collisionWall == Wall::LEFT) {

		LockX(go);

	} else {

		LockY(go);

	}

}

int GameObject::GetCollisionWall(GameObject * go) {

	if(!CollidesWith(go)) return -1;

	float dX, dY;

	if(x > go->GetX()) dX = go->GetX() + go->GetWidth() - x;
	else dX = x + width - go->GetX();

	if(y > go->GetY()) dY = go->GetY() + go->GetHeight() - y;
	else dY = y + height - go->GetY();

	if(dX > dY) {

		if(y > go->GetY()) return Wall::TOP;
		else return Wall::BOTTOM;

	} else {

		if(x > go->GetX()) return Wall::LEFT;
		else return Wall::RIGHT;

	}

}
