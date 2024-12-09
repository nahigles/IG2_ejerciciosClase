#include "Clock.h"

const int Clock::CLOCK_RADIUS = 300;

Clock::Clock(SceneManager* sManager)
{
	sceneManager = sManager;
}

bool Clock::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	// Rotate spheres (a)
	if (evt.keysym.sym == SDLK_a) {
		clockNode->roll(Ogre::Degree(5));
		cout << "Rotating spheres 5 radians" << endl;
	}

	// Rotate spheres (s)
	else if (evt.keysym.sym == SDLK_s) {
		clockNode->roll(Ogre::Degree(-5));
		cout << "Rotating spheres -5 radians" << endl;
	}

	// Rotate the hours hand (d)
	else if (evt.keysym.sym == SDLK_d) {
		hourHandNode->roll(Ogre::Degree(5));
		cout << "Rotating hours hand 5 radians" << endl;
	}

	// Rotate the hours hand (f)
	else if (evt.keysym.sym == SDLK_f) {
		hourHandNode->roll(Ogre::Degree(-5));
		cout << "Rotating hours hand -5 radians" << endl;
	}

	// Rotate the hourHandNodePositional hand (g)
	else if (evt.keysym.sym == SDLK_g) {
		hourHandNodePositional->roll(Ogre::Degree(5));
		cout << "Rotating hourHandNodePositional hand 5 radians" << endl;
	}

	// Rotate the hourHandNodePositional hand (h)
	else if (evt.keysym.sym == SDLK_h) {
		hourHandNodePositional->roll(Ogre::Degree(-5));
		cout << "Rotating hourHandNodePositional hand -5 radians" << endl;
	}

	return true;
}

void Clock::setupClock()
{
	//------------------------------------------------------------------------
	// The clock

	// Create the main node and hours node (from root)
	clockNode = sceneManager->getRootSceneNode()->createChildSceneNode("clock");
	hoursNode = clockNode->createChildSceneNode("hours");

	// Offset for sphere positioning
	double inc = 2 * 3.1415 / 12;
	Ogre::SceneNode* mHourNode;

	// Create the spheres
	for (int i = 0; i < 12; i++) {
		Entity* hour = sceneManager->createEntity("sphere.mesh");
		mHourNode = hoursNode->createChildSceneNode("Hour " + std::to_string(i + 1));
		mHourNode->setScale(0.4, 0.4, 0.4);
		mHourNode->attachObject(hour);
		mHourNode->setPosition(CLOCK_RADIUS * Ogre::Math::Cos(inc * i), CLOCK_RADIUS * Ogre::Math::Sin(inc * i), 0);
	}

	// Modify the even hours
	Ogre::SceneNode* nodo;

	// Get each node by its name
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 1) {
			nodo = sceneManager->getSceneNode("Hour " + std::to_string(i + 1));
			nodo->setScale(0.2, 0.2, 0.2);
		}
	}

	// Adding the clock hands
	handsNode = clockNode->createChildSceneNode("hands");

	// Hours hand
	// Make hours hands independet
	hourHandNodePositional = clockNode->createChildSceneNode("hoursPositional");
	hourHandNode = hourHandNodePositional->createChildSceneNode("Hours Hand");

	//hourHandNode = handsNode->createChildSceneNode("Hours Hand");
	Entity* cubo = sceneManager->createEntity("cube.mesh");
	hourHandNode->attachObject(cubo);
	hourHandNode->setScale(2, 0.15, 0.02);
	hourHandNode->setPosition(80, 0, 0);

	// Minutes hand
	minuteHandNode = handsNode->createChildSceneNode("Minutes Hand");
	cubo = sceneManager->createEntity("cube.mesh");
	minuteHandNode->attachObject(cubo);
	minuteHandNode->setScale(2.5, 0.1, 0.02);
	minuteHandNode->setPosition(0, 100, 0);
	minuteHandNode->roll(Ogre::Degree(90));

	// Seconds hand
	secondHandNode = handsNode->createChildSceneNode("Seconds Hand");
	cubo = sceneManager->createEntity("cube.mesh");
	secondHandNode->attachObject(cubo);
	secondHandNode->setScale(2.5, 0.02, 0.02);
	secondHandNode->setPosition(100, 0, 0);
	secondHandNode->setPosition(0, -100, 0);
	secondHandNode->roll(Ogre::Degree(-90));
}


