#ifndef GameObject_h
#define GameObject_h

#include "SDL.h"
#include "TextureManager.h"
#include "LevelManager.h"
#include "Game.h"
#include <vector>

class LevelManager;
class Game;

class GameObject {

public:

	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height);
	GameObject(const char * textureSheet, float init_x, float init_y, int init_width, int init_height, 
		float scale);

	~GameObject();

	void UpdateCollisions(LevelManager * game);
	void Collide();
	virtual void UpdateObject(LevelManager * game);
	virtual void Update(LevelManager * game) = 0;
	virtual void RenderObject();

	bool CollidesWith(GameObject * go);
	virtual void OnCollision(GameObject * go, LevelManager * game) {}
	float DistanceToSquared(GameObject * go);
	bool IsSolid();

	bool OnScreen();

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
	void SetVY(float new_vY);
	void SetX(float new_x);
	void SetY(float new_y);
	int GetHealth();
	int GetMaxHealth();
	void SetMaxHealth(int h);
	bool IsDamagable();
	void SetDamagable(bool d);

	bool IsAt(float xTarget, float yTarget);
	
	virtual void DealDamage(int d, LevelManager * game, GameObject * go);
	virtual void Heal(int h);
	
	float GetXOverlap(GameObject * go);
	float GetYOverlap(GameObject * go);

	void SetCollidable(bool c);
	void SetMoveable(bool m);
	void SetSolid(bool s);

	int GetRenderLayer();

	SDL_Rect * GetSrcRect();

	bool IsPushedUp();
	bool IsPushedDown();
	bool IsPushedLeft();
	bool IsPushedRight();

	virtual bool OverrideCollision(GameObject * go);

	void SetGrav(float g);
	void SetDecceleration(float d);
	
protected:

	float x, y, width, height, tileX = 0, tileY = 0, vX, vY, grav = 0, decceleration = 1, scale;
	int spriteWidth, spriteHeight;
	
	SDL_Texture * texture;
	SDL_Rect srcRect, destRect;
	
	bool collidable = false, grounded, dead = false, moveable = true, solid = true;
	enum Wall {
		TOP = 1,
		RIGHT = 2,
		BOTTOM = 3,
		LEFT = 4
	};

	bool damageable = false;
	int maxHealth = -1, health = -1, damageDelay = 20, damageFlash = 0;

	virtual void OnDeath(LevelManager * game);

	int renderLayer = 1;

	bool visible = true;

	bool pushedLeft = false, pushedRight = false, pushedUp = false, pushedDown = false;

	std::vector<GameObject *> collisions;
	
};

#endif