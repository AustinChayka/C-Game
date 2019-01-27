#ifndef LevelManager_h
#define LevelManager_h

#include "StateManager.h"
#include <vector>
#include "GameObject.h"

class StateManager;
class GameObject;

class LevelManager {
	
public:

	LevelManager();

	~LevelManager();

	void LoadLevel(int n);

	void GenerateLevel(char * path, int sizeX, int sizeY);

	void Update(StateManager * sm);
	void Render();

	void AddObject(GameObject * go);
	std::vector<GameObject *> GetObjects();

	void NextLevel();

	static GameObject * player;

private:

	std::vector<GameObject *> objects;

	int currentLevel = 0;
	
};

#endif