#include "Blade.h"


const int Blade::BLADE_ANCHO = 1;
const int Blade::BLADE_ALTO = 3;
const int Blade::BLADE_LARGO = 0.2;

Blade::Blade(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng)
{
	init();
}

void Blade::init()
{
	// Creo Pala
	palaNode = mNode->createChildSceneNode("nPala");
	Entity* entPala = mSM->createEntity("Pala", "cube.mesh");
	palaNode->attachObject(entPala);
	palaNode->setScale(BLADE_ANCHO, BLADE_ALTO, BLADE_LARGO);
	palaNode->setPosition(0, BLADE_ALTO * 50, 0);

	// Creo Ogrehead
	ogreheadNode = mNode->createChildSceneNode("nOgreHead");
	Entity* entOgrehead = mSM->createEntity("OgreHead", "ogrehead.mesh");
	ogreheadNode->attachObject(entOgrehead);
	ogreheadNode->setScale(1, 1, 0.1);
	ogreheadNode->setPosition(0, BLADE_ALTO * 100 - 50, 4);
}
