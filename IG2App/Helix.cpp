#include "Helix.h"

Helix::Helix(Vector3 initPos, SceneNode* node, SceneManager* sceneMng, int bladeNumber) : IG2Object(initPos, node, sceneMng)
{
	n = bladeNumber;

	init();
}

Helix::~Helix()
{
	// Destruyo palas
	for (auto it = palas.begin(); it != palas.end(); ++it)
		delete (*it);
}

void Helix::roll(int grados)
{
	mNode->roll(Degree(grados));
}

void Helix::init()
{
	// Palas
	double cacho = 360.0 / n;

	for (int i = 0; i < n; i++) {
		SceneNode* nodoHijo = mNode->createChildSceneNode(/*"BladeNode" + to_string(i)*/);
		Blade* blade = new Blade(initialPosition, nodoHijo, mSM);
		nodoHijo->roll(Degree(i * cacho));
	}

	// Centro
	centerNode = mNode->createChildSceneNode(/*"nCenter"*/);
	Entity* ent = mSM->createEntity(/*"mCenter",*/ "sphere.mesh");
	centerNode->attachObject(ent);
	centerNode->setScale(0.05, 0.05, 0.1);
}
