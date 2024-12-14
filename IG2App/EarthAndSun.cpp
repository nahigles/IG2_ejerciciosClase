#include "EarthAndSun.h"

const int EarthAndSun::EarthDistance = 200;

EarthAndSun::EarthAndSun(SceneManager* sManager)
{
	sceneManager = sManager;
}

void EarthAndSun::setupEarthAndSun()
{
    //------------------------------------------------------------------------
    // Sun and earth

    sun = sceneManager->getRootSceneNode()->createChildSceneNode();
    Entity* ent = sceneManager->createEntity("sphere.mesh");
    sun->attachObject(ent);
    sun->scale(0.2, 0.2, 0.2);


    // Re-positioning
    //alpha = 0;
    //earth =  sceneManager->getRootSceneNode()->createChildSceneNode();
    //ent = sceneManager->createEntity("sphere.mesh");
    //earth->attachObject(ent);
    //earth->scale (0.1, 0.1, 0.1);
    //earth->setPosition(EarthDistance*Ogre::Math::Cos(Ogre::Degree(alpha)), 0, EarthDistance*Ogre::Math::Sin(Ogre::Degree(alpha)));


    // Fake node
    //alpha = -5;
    //earthFake = sceneManager->getRootSceneNode()->createChildSceneNode("tierra fake");
    //earth = earthFake->createChildSceneNode("tierra");
    //ent = sceneManager->createEntity("sphere.mesh");
    //earth->translate(EarthDistance, 0, 0);
    //earth->scale(0.1, 0.1, 0.1);
    //earth->attachObject(ent);


    // The trick
    alpha = -5;
    earth = sceneManager->getRootSceneNode()->createChildSceneNode();
    ent = sceneManager->createEntity("sphere.mesh");
    earth->attachObject(ent);
    earth->translate(EarthDistance, 0, 0);
    earth->scale(0.1, 0.1, 0.1);
}

bool EarthAndSun::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    if (evt.keysym.sym == SDLK_w) {

        // Re-positioning
        //alpha -= 5;
        //earth->setPosition(EarthDistance*Ogre::Math::Cos(Ogre::Degree(alpha)), 0, EarthDistance*Ogre::Math::Sin(Ogre::Degree(alpha)));
        //cout << "Re-positioning with alpha= " << alpha << endl;

        // Fake node
        //earthFake->yaw(Ogre::Degree(alpha));
        //cout << "Fake node with alpha= " << alpha << endl;

        // The trick!
        earth->translate(-EarthDistance, 0, 0, SceneNode::TS_LOCAL);
        earth->yaw(Ogre::Degree(alpha));
        earth->translate(EarthDistance, 0, 0, SceneNode::TS_LOCAL);

        cout << "The trick with alpha= " << alpha << endl;
    }

    return true;
}
