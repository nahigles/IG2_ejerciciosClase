#include "SistemaParticulas.h"

SistemaParticulas::SistemaParticulas(SceneManager* sManager)
{
	mSM = sManager;
}

void SistemaParticulas::setupParticulas()
{
	//------------------------------------------------------------------------
// Creating the floor

	MeshManager::getSingleton().createPlane("floorParticle", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Plane(Vector3::UNIT_Y, 0),
		1500, 1500, 200, 200, true, 1, 5, 5,
		Vector3::UNIT_Z);

	// Creating the plane
	Entity* ent = mSM->createEntity("exampleFloorParticle", "floorParticle");
	ent->setMaterialName("example/stonesFloor");
	SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
	floor->attachObject(ent);


	//------------------------------------------------------------------------
	// Creating Sinbad

	sinbadEnt = mSM->createEntity("Sinbad.mesh");
	sinbadNode = mSM->getRootSceneNode()->createChildSceneNode();
	sinbadNode->attachObject(sinbadEnt);
	sinbadNode->scale(5, 5, 5);
	sinbadNode->setPosition(0, 25, 0); // On the floor!
	sinbadNode->setInitialState();

	//------------------------------------------------------------------------
	// Billboard effect (smiley) in sphere

	Entity* sphereEnt = mSM->createEntity("sphere.mesh");
	SceneNode* sphereNode = mSM->getRootSceneNode()->createChildSceneNode();
	sphereNode->attachObject(sphereEnt);
	sphereNode->setPosition(Vector3(150, 100, 0));
	sphereEnt->setMaterialName("example/esferaSmile");



	//------------------------------------------------------------------------
	// Billboard effect (panel) in sphere

//    SceneNode* bbNode = mSM->getRootSceneNode()->createChildSceneNode();
//    Ogre::BillboardSet* bbSet = mSM->createBillboardSet(1);
//    bbSet->setDefaultDimensions(80, 40);
//    bbSet->setMaterialName("example/panel");
//    bbNode->attachObject(bbSet);
//    bbSet->createBillboard({ 0, 50, -50});


	//------------------------------------------------------------------------
	// Particle System

	pSys = mSM->createParticleSystem("psSmoke", "example/smokeParticleSystem");
	pSys->setEmitting(false);
	mPSNode = mSM->getRootSceneNode()->createChildSceneNode();
	mPSNode->setPosition(-150, 100, 0);
	mPSNode->attachObject(pSys);


	// Nodo Centro
	centerNode = mSM->getRootSceneNode()->createChildSceneNode();

	// Esfera
	Entity* entEsfera = mSM->createEntity("sphere.mesh");
	esferaNode = centerNode->createChildSceneNode();
	esferaNode->attachObject(entEsfera);
	esferaNode->setScale(0.3, 0.3, 0.3);
	esferaNode->translate(700, 100, 0);

	// Sistema particulas 2
	pSys2 = mSM->createParticleSystem("psBlueSmoke", "example/blueSmokeParticleSystem");
	pSys2->setEmitting(false);
	mPSNode2 = esferaNode->createChildSceneNode();
	mPSNode2->setPosition(-150, 100, 0);
	mPSNode2->attachObject(pSys2);
}

bool SistemaParticulas::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_x) {
		pSys->setEmitting(true);
	}
	else if (evt.keysym.sym == SDLK_c) {
		pSys2->setEmitting(true);
	}

	return true;
}

void SistemaParticulas::frameRendered(const Ogre::FrameEvent& evt)
{
	centerNode->yaw(Degree(1));
}
