#include "Book.h"

#include "ItemObject.h"

Book::Book(const char * path, const char * name, const char * flavor) : Item(path, name, flavor) {}

Book::~Book() {}

void Book::OnPickup(LevelManager * game, Player * p) {

	for(int i = 0; i < p->GetItems()->size(); i++) 
		if(p->GetItems()->at(i) != this && dynamic_cast<Book *>(p->GetItems()->at(i)) != nullptr) {
			game->AddObject(new ItemObject(p->GetXCenter() - 12, p->GetY() + p->GetHeight() - 24, p->GetItems()->at(i)));
			p->GetItems()->erase(p->GetItems()->begin() + i);
		}

}
