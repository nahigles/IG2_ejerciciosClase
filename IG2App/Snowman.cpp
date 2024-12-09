#include "Snowman.h"

Snowman::Snowman(SceneManager* sManager)
{
	sceneManager = sManager;
}

void Snowman::setupSnowman()
{
	//------------------------------------------------------------------------
	// The snowman

	// Create the main scene node (from root)
	snowman = sceneManager->getRootSceneNode()->createChildSceneNode("snowMan");

	// Create the head
	head = snowman->createChildSceneNode("head");
	Ogre::Entity* ent = sceneManager->createEntity("sphere.mesh");
	head->attachObject(ent);

	// Nodes for the head (eyes, nose and mouth)
	leftEye = head->createChildSceneNode("leftEye");
	ent = sceneManager->createEntity("sphere.mesh");
	leftEye->attachObject(ent);
	leftEye->setScale(0.1, 0.1, 0.1);
	leftEye->setPosition(30, 30, 100);

	rightEye = head->createChildSceneNode("rightEye");
	ent = sceneManager->createEntity("sphere.mesh");
	rightEye->attachObject(ent);
	rightEye->setScale(0.1, 0.1, 0.1);
	rightEye->setPosition(-30, 30, 100);

	nose = head->createChildSceneNode("nose");
	ent = sceneManager->createEntity("sphere.mesh");
	nose->attachObject(ent);
	nose->setScale(0.1, 0.1, 0.1);
	nose->setPosition(0, 15, 100);

	mouth = head->createChildSceneNode("mouth");
	ent = sceneManager->createEntity("sphere.mesh");
	mouth->attachObject(ent);
	mouth->setScale(0.2, 0.1, 0.1);
	mouth->setPosition(0, -20, 100);

	// Create the body
	body = snowman->createChildSceneNode("body");
	ent = sceneManager->createEntity("sphere.mesh");
	body->attachObject(ent);
	body->setScale(1.5, 1.5, 1.5);

	bellyButton = body->createChildSceneNode("bellyButton");
	ent = sceneManager->createEntity("sphere.mesh");
	bellyButton->attachObject(ent);
	bellyButton->setScale(0.1, 0.1, 0.1);
	bellyButton->setPosition(0, 0, 100);

	// Move the body (and also the belly button)
	body->setPosition(0, -230, 0);
}
