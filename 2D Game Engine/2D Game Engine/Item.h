#ifndef Item_h
#define Item_h

#include "LevelManager.h"
#include "Player.h"
#include "SDL.h"
#include "Projectile.h"

class Item {

public:

	Item(const char * iconPath, const char * name, const char * itemFlavor);

	virtual void Update(LevelManager * game, Player * p);
	virtual void OnPickup(LevelManager * game, Player * p);
	virtual void OnDamageTaken(LevelManager * game, GameObject * go, Player * p);
	virtual int OverrideDamageTotal(int damage, GameObject * go, Player * p);
	virtual bool OverrideDefaultProjectile(Player * p, Projectile *& proj);
	virtual void OnShotFired(LevelManager * game, Player * p, Projectile *& proj);
	virtual void OnDamageDelt(LevelManager * game, Player * p, GameObject * go, bool crit);
	virtual void UpdateProjectile(LevelManager * game, Player * p, Projectile * proj);
	virtual void OnKill(LevelManager * game, Player * p, GameObject * go);
	virtual void Render();

	SDL_Texture * GetTexture();
	SDL_Texture * GetNameText();
	SDL_Texture * GetFlavorText();

	int GetNameLength();
	int GetFlavorTextLength();
	int GetLayer();

	const char * GetTexturePath();

	bool IsSynergyActive();

	~Item();

protected:

	SDL_Texture * icon;
	SDL_Texture * nameText;
	SDL_Texture * flavorText;

	int nameLength, flavorTextLength, renderLayer = 1;
	const char * texturePath;

	const char * synergy;
	bool synergyActive = false;

};

#endif