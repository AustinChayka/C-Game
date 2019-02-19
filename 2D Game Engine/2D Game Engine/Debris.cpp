#include "Debris.h"

Debris::Debris(const char * filepath, int img_width, int img_height, int init_tileX, int init_tileY, float scale, float x, float y)  :
	Particle(x, y, img_width, img_height, 255, 255, 255, 0) {

	tileX = init_tileX;
	tileY = init_tileY;

	rows = 2 * (rand() % 4 + 3);
	columns = rows + 2 * (rand() % 2 - 1);

	for(int i = 0; i < rows * columns; i++) {
		pieces.push_back(new Particle(filepath, x + (i % rows) * (int)(img_width * scale / rows),
			y + (i / rows) * (int)(img_height * scale / columns), (int)(img_width * scale / rows), (int)(img_height * scale / columns),
			0, 0, 1));
		pieces.back()->SetVX(0.25f * (rand() % 2 - 1 + i % rows - rows / 2));
		pieces.back()->SetVY(0.25f * (rand() % 2 - 1 + i / rows - columns));
		pieces.back()->SetFadeSpeed(1.5f);
	}
	
}

Debris::~Debris() {
	
}

void Debris::Update(LevelManager * game) {

	for(int i = 0; i < pieces.size(); i++) {

		pieces.at(i)->UpdateObject(game);
		
		pieces.at(i)->SetVY(pieces.at(i)->GetVY() + 0.07f);
	
		for(auto go : game->GetObjects()) if(pieces.at(i)->CollidesWith(go) && (!go->IsMoveable() && go->IsSolid())) {

			pieces.at(i)->SetVX(0);
			pieces.at(i)->SetVY(0);
			
		}

		pieces.at(i)->GetSrcRect()->w = width / rows;
		pieces.at(i)->GetSrcRect()->h = height / columns;
		pieces.at(i)->GetSrcRect()->x = (i % rows) * (width / rows) + tileX * width;
		pieces.at(i)->GetSrcRect()->y = (i / rows) * (height / columns) + tileY * height;

		if(pieces.at(i)->IsDead()) {
			delete pieces.at(i);
			pieces.erase(pieces.begin() + i);
			i--;
		}

	}

	if(pieces.size() == 0) dead = true;

}

void Debris::RenderObject() {

	for(auto p : pieces) p->RenderObject();

}