#ifndef Particle_h
#define Particle_h

#include "GameObject.h"

class GameObject;

class Particle : public GameObject {

public:

	Particle(float init_x, float init_y, float init_width, float init_height, float r, float g, float b, float a);
	Particle(const char * filepath, float init_x, float init_y, float init_width, float init_height, float scale);
	~Particle();

	virtual void Update(LevelManager * game);
	virtual void RenderObject();

	void SetFadeSpeed(float s);
	void SetShrinkSpeed(float s);

private:

	bool img;

protected:

	float red, green, blue, alpha, fadeSpeed = 0.5f, shrinkSpeed = 0.1f;
	SDL_Rect rect;
	bool shrink = true, fade = true;

};

#endif