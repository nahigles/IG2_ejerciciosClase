#include "MaterialesLucesSombras2.h"

MaterialesLucesSombras2::MaterialesLucesSombras2(SceneManager* sManager)
{
	mSM = sManager;
}

void MaterialesLucesSombras2::setupMaterialesLucesSombras2()
{
	//mSM->setShadowTechnique(SHADOWTYPE_STENCIL_ADDITIVE);

	// Plano
	MeshManager::getSingleton().createPlane("Planee", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Plane(Vector3::UNIT_Y, 0),
		1080, 800, 100, 80,
		true, 1, 5.0, 5.0, Vector3::UNIT_Z);

	// entidad
	Entity* entPlane = mSM->createEntity("Planee");
	//entPlane->setMaterialName("example/chromeFloor");
	//entPlane->setMaterialName("example/waterFloor");
	entPlane->setMaterialName("example/stonesFloor");
	// nodo
	SceneNode* planoNodo = mSM->getRootSceneNode()->createChildSceneNode();
	planoNodo->attachObject(entPlane);


	// Ogrehead
	Entity* entOgreHead = mSM->createEntity("ogrehead.mesh");
	// nodo
	mOgreheadNode = mSM->getRootSceneNode()->createChildSceneNode();
	mOgreheadNode->attachObject(entOgreHead);
	mOgreheadNode->scale(0.7, 0.7, 0.7);
	mOgreheadNode->setPosition(0, 20, 0);

	// Esfera
	esferaNode = mSM->getRootSceneNode()->createChildSceneNode();
	Entity* esferaEnt = mSM->createEntity("sphere.mesh");
	//esferaEnt->setMaterialName("example/colorTurquesa");
	esferaEnt->setMaterialName("example/colorNaranja");
	esferaNode->attachObject(esferaEnt);
	esferaNode->setPosition(80, 30, 0);
	esferaNode->setScale(0.25, 0.25, 0.25);

	//Luz direccional
	Light* directionalLight = mSM->createLight("Direcctional");
	directionalLight->setType(Light::LT_DIRECTIONAL);
	directionalLight->setDiffuseColour(1, 1, 1);
	directionalLight->setDirection(0, -1, 0);
	// nodo
	directionalLightNode = mSM->getRootSceneNode()->createChildSceneNode();
	directionalLightNode->attachObject(directionalLight);
}

bool MaterialesLucesSombras2::keyPressed(const OgreBites::KeyboardEvent& evt)
{

	return true;
}
