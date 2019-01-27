#ifndef Particle_h
#define Particle_h

#include "GameObject.h"

class Particle : public GameObject {

public:

	Particle(float init_x, float init_y, float init_width, float init_height, float r, float g, float b, float a);
	~Particle();

	virtual void Update(LevelManager * game);
	virtual void RenderObject();

private:

	float red, green, blue, alpha;
	SDL_Rect rect;
	bool shrink = true, fade = true;

};

#endif