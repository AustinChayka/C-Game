#ifndef LevelManager_h
#define LevelManager_h

#include "StateManager.h"
#include <vector>
#include "ImageTile.h"

class StateManager;
class GameObject;
class ImageTile;
class Room;

class LevelManager {
	
public:

	LevelManager();

	~LevelManager();

	void LoadLevel(int n);

	void GenerateLevel(int size, int seed);

	void Update(StateManager * sm);
	void Render();

	void AddObject(GameObject * go);
	std::vector<GameObject *> * GetObjects();
	void AddTile(ImageTile * it);
	std::vector<Room *> * GetRooms();

	void NextLevel();

	static GameObject * player;

private:

	std::vector<GameObject *> * objects;
	std::vector<ImageTile *> * tiles;
	std::vector<Room *> * rooms;

	std::vector<GameObject *> * allObjects;

	int currentLevel = 0, leftOverEnemies = 0;

	bool reloaded;
	
};

#endif