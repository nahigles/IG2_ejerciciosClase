#include "Blade.h"


const double Blade::BLADE_ANCHO = 0.4;
const double Blade::BLADE_ALTO = 2;
const double Blade::BLADE_LARGO = 0.05;

Blade::Blade(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng)
{
	init();
}

void Blade::init()
{
	// Creo Pala
	palaNode = mNode->createChildSceneNode();
	Entity* entPala = mSM->createEntity("cube.mesh");
	palaNode->attachObject(entPala);
	palaNode->setScale(BLADE_ANCHO, BLADE_ALTO, BLADE_LARGO);
	palaNode->setPosition(initialPosition.x, initialPosition.y + BLADE_ALTO * 50, initialPosition.z);

	// Creo Ogrehead
	ogreheadNode = mNode->createChildSceneNode();
	Entity* entOgrehead = mSM->createEntity("ogrehead.mesh");
	ogreheadNode->attachObject(entOgrehead);
	ogreheadNode->setScale(0.5, 0.5, 0.1);
	ogreheadNode->setPosition(initialPosition.x, initialPosition.y + BLADE_ALTO * 100 - 25, initialPosition.z + BLADE_LARGO*100);
}
