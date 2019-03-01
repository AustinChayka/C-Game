#include "Spike.h"

Spike::Spike(float x, float y) : GameObject("assets/Spikes.png", x, y, 20, 10, 3) {

	collidable = true;
	solid = false;
	moveable = false;

}

Spike::~Spike() {}

void Spike::Update(LevelManager * game) {
	
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

	if(activated) go->DealDamage(3, game, this);
	else if(!triggered) {
		triggered = true;
		delay = activationDelay;
	}

}
