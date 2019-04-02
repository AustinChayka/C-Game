#ifndef JarOfAir_h
#define JarOfAir_h

#include "Item.h"

class JarOfAir : public Item {

public:

	JarOfAir();

	~JarOfAir();

	void OnPickup(LevelManager * game, Player * p);

};

#endif