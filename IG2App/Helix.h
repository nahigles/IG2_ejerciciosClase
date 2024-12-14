#pragma once
#include "IG2Object.h"
#include "Blade.h"
#include <vector>

using namespace std;
using namespace Ogre;

class Helix : public IG2Object
{
protected:
	std::vector<Blade*> palas;
	SceneNode* centerNode = nullptr;

	int n;

public:
	Helix(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int bladeNumber);
	~Helix();

protected:
	virtual void init();
};

