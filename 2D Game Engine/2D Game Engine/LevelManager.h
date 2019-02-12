#ifndef LevelManager_h
#define LevelManager_h

#include "StateManager.h"
#include <vector>
#include "GameObject.h"
#include "ImageTile.h"

class StateManager;
class GameObject;
class ImageTile;

class LevelManager {
	
public:

	LevelManager();

	~LevelManager();

	void LoadLevel(int n);

	void GenerateLevel(int sizeX, int sizeY);

	void Update(StateManager * sm);
	void Render();

	void AddObject(GameObject * go);
	std::vector<GameObject *> GetObjects();
	void AddTile(ImageTile * it);

	void NextLevel();

	static GameObject * player;

private:

	std::vector<GameObject *> objects;
	std::vector<ImageTile *> tiles;

	int currentLevel = 0;
	
};

#endif