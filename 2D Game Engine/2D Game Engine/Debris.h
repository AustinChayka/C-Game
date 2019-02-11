#ifndef Debris_h
#define Debris_h

#include "Particle.h"

class Debris : public Particle {

public:

	Debris(const char * filepath, int img_width, int img_height, int init_tileX, int init_tileY, float scale, float x, float y);

	~Debris();

	void Update(LevelManager * game);

	void RenderObject();

private: 

	std::vector<Particle *> pieces;

	int rows = 4, columns = 8;

};

#endif