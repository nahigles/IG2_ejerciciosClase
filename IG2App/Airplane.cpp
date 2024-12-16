#include "Airplane.h"

const double Airplane::CUERPO_ANCHO = 1;
const double Airplane::CUERPO_ALTO = 1;
const double Airplane::CUERPO_LARGO = 4;

const double Airplane::ALA_ANCHO = 2;
const double Airplane::ALA_ALTO = 0.2;
const double Airplane::ALA_LARGO = 1;

Airplane::Airplane(Vector3 initPos, SceneNode* node, SceneManager* sceneMng) : IG2Object(initPos, node, sceneMng)
{
	init();
}

void Airplane::init()
{
	// Cuerpo
	SceneNode* cuerpoNode = mNode->createChildSceneNode("nCuerpo");
	cuerpo = new IG2Object({ 0,0,0 }, cuerpoNode, mSM, "sphere.mesh");
	cuerpoNode->setScale(CUERPO_ANCHO, CUERPO_ALTO, CUERPO_LARGO);
	cuerpoNode->setPosition(initialPosition);

	// Ala derecha
	SceneNode* alaDerNode = mNode->createChildSceneNode("nAlaDer");
	alaDerecha = new IG2Object({ 0,0,0 }, alaDerNode, mSM, "cube.mesh");
	alaDerNode->setScale(ALA_ANCHO, ALA_ALTO, ALA_LARGO);
	alaDerNode->setPosition(initialPosition.x - ALA_ANCHO * 100, initialPosition.y, initialPosition.z);

	// Ala izquierda
	SceneNode* alaIzqNode = mNode->createChildSceneNode("nAlaIzq");
	alaIzquierda = new IG2Object({ 0,0,0 }, alaIzqNode, mSM, "cube.mesh");
	alaIzqNode->setScale(ALA_ANCHO, ALA_ALTO, ALA_LARGO);
	alaIzqNode->setPosition(initialPosition.x + ALA_ANCHO * 100, initialPosition.y, initialPosition.z);

	// Timon
	timonNode = mNode->createChildSceneNode("nTimon");
	Entity* timonEnt = mSM->createEntity("mTimon", "cube.mesh");
	timonNode->attachObject(timonEnt);
	timonNode->setScale(0.1, 1, 2);
	timonNode->pitch(Degree(45));
	timonNode->setPosition(initialPosition.x, initialPosition.y + CUERPO_ALTO*100, initialPosition.z-CUERPO_LARGO*60);

	// Piloto
	pilotoNode = mNode->createChildSceneNode("nPiloto");
	Entity* pilotoEnt = mSM->createEntity("mPiloto", "ninja.mesh");
	pilotoNode->attachObject(pilotoEnt);
	pilotoNode->yaw(Degree(180));
	pilotoNode->setPosition(initialPosition.x, initialPosition.y, initialPosition.z + CUERPO_LARGO / 2 * 100);

	// Helice derecha
	SceneNode* heliceDerNode = mNode->createChildSceneNode("nHeliceDer");
	heliceDerecha = new Helix({ 0,0,0 }, heliceDerNode, mSM, 10);
	heliceDerNode->setPosition(initialPosition.x - ALA_ANCHO * 100, initialPosition.y, initialPosition.z + ALA_LARGO * 50);
	heliceDerNode->setScale(0.5, 0.5, 0.5);

	// Helice izquierda
	SceneNode* heliceIzqNode = mNode->createChildSceneNode("nHeliceIzq");
	heliceIzquierda = new Helix({ 0,0,0 }, heliceIzqNode, mSM, 10);
	heliceIzqNode->setPosition(initialPosition.x + ALA_ANCHO * 100, initialPosition.y, initialPosition.z + ALA_LARGO*50);
	heliceIzqNode->setScale(0.5, 0.5, 0.5);
}

bool Airplane::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_w) {
		heliceDerecha->roll(5);
		heliceIzquierda->roll(-5);
	}

	return true;
}
