#include "Spike.h"

#include "Enemy.h"
#include "BleedStatus.h"

Spike::Spike(float x, float y) : GameObject("assets/Spikes.png", x, y, 20, 10, 3) {

	collidable = true;
	solid = false;
	moveable = false;

}

Spike::~Spike() {}

void Spike::Update(LevelManager * game) {

	if(bleedDelay > 0) bleedDelay--;
	
	if(triggered) {
		if(delay == 0) {
			triggered = false;
			activated = true;
			delay = activationDelay;
			tileX = 2;
		} else {
			delay--;
			tileX = 1;
		}
	} else if(activated) {
		if(delay == 0) {
			activated = false;
			tileX = 0;
		} else delay--;
	}
	
}

void Spike::OnCollision(GameObject * go, LevelManager * game) {

	if(!go->IsDamagable()) return;

	if(activated) {
		go->DealDamage(1, game, this);
		if(dynamic_cast<Enemy *>(go) != nullptr && bleedDelay == 0) {
			bleedDelay = 60;
			((Enemy *) go)->AddStatus(new BleedStatus(2));
		}
	}
	else if(!triggered) {
		triggered = true;
		delay = activationDelay;
	}

}
