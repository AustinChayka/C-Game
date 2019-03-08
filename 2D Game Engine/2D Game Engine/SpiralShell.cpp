#include "SpiralShell.h"

SpiralShell::SpiralShell() : Item("assets/Items/SpiralShell.png", "Spiral Shell", "Curly") {}

SpiralShell::~SpiralShell() {}

void SpiralShell::UpdateProjectile(LevelManager * game, Player * p, Projectile * proj) {

	proj->SetX(cos(proj->GetLifeTime() * 10 * M_PI / 180) * radius + 
		proj->GetSpawnX() + proj->GetSpawnVX() * 6 * proj->GetLifeTime() / radius);
	proj->SetY(-sin(proj->GetLifeTime() * 10 * M_PI / 180) * radius + 
		proj->GetSpawnY() + proj->GetSpawnVY() * 6 * proj->GetLifeTime() / radius);
		
}
