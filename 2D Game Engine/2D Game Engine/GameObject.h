#ifndef GameObject_h
#define GameObject_h

#include "SDL.h"
#include "TextureManager.h"
#include "LevelManager.h"
#include "Game.h"

class LevelManager;
class Game;

class GameObject {

public:

	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height);
	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
		float scale);

	~GameObject();

	void UpdateObject(LevelManager * game);
	virtual void Update(LevelManager * game) = 0;
	virtual void RenderObject();

	bool CollidesWith(GameObject * go);
	virtual void OnCollision(GameObject * go) {}

	float GetX();
	float GetY();
	float GetVX();
	float GetVY();
	int GetWidth();
	int GetHeight();
	float GetXCenter();
	float GetYCenter();
	bool IsDead();
	bool IsMoveable();
	void SetVX(float new_vX);
	void SetX(float new_x);
	void SetY(float new_y);
	
	virtual void DealDamage(int d);

protected:

	float x, y, width, height, tileX = 0, tileY = 0, vX, vY, scale;
	int spriteWidth, spriteHeight;
	
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
	
	bool collidable = false, grounded, dead = false, moveable = true;
	void LockCollision(GameObject * go);
	int GetCollisionWall(GameObject * go);
	enum Wall {
		TOP = 1,
		RIGHT = 2,
		BOTTOM = 3,
		LEFT = 4
	};

	void LockX(GameObject * go);
	void LockY(GameObject * go);

	bool damageable = false;
	int health = -1;
	
};

#endif