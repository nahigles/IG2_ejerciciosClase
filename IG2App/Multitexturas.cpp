#include "Multitexturas.h"

Multitexturas::Multitexturas(SceneManager* sManager)
{
	mSM = sManager;
}

void Multitexturas::setupMultitexturas()
{
    //------------------------------------------------------------------------
    // Creating the floor

    // MAR
    //MeshManager::getSingleton().createPlane("floorMulti", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    //    Plane(Vector3::UNIT_Y, 0),
    //    500, 500, 200, 200, true, 1, 1, 1,
    //    Vector3::UNIT_Z);

    //// Creating the plane
    //Entity* ent = mSM->createEntity("exampleFloorMulti", "floorMulti");
    ////ent->setMaterialName("mar/centroClaro");
    //ent->setMaterialName("mar/bordesOscuros");
    //SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
    //floor->attachObject(ent);

    // MAR Y TIERRA
        MeshManager::getSingleton().createPlane("floorMulti", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        Plane(Vector3::UNIT_Y, 0),
        1500, 1500, 200, 200, true, 1, 1, 1,
        Vector3::UNIT_Z);

    // Creating the plane
    Entity* ent = mSM->createEntity("exampleFloorMulti", "floorMulti");
    ent->setMaterialName("mar/tierra");
    SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
    floor->attachObject(ent);

    // CIELO
    Ogre::Plane plane;
    plane.d = 1000;
    plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;
    mSM->setSkyPlane(true, plane, "example/sky", 1500, 50, true, 1.5, 50, 50);

    //------------------------------------------------------------------------
    // Creating Sinbad

    sinbadEnt = mSM->createEntity("Sinbad.mesh");
    sinbadNode = mSM->getRootSceneNode()->createChildSceneNode();
    sinbadNode->attachObject(sinbadEnt);
    sinbadNode->scale(10, 10, 10);
    sinbadNode->setPosition(0, 50, -425); // On the floor!
    sinbadNode->setInitialState();


    //------------------------------------------------------------------------
    // Multitexturing...

    // To do...



    //------------------------------------------------------------------------
    // Skyplane

    // To do...



    //------------------------------------------------------------------------
    // Mirror example

    // To do...

}

bool Multitexturas::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	return true;
}

void Multitexturas::frameRendered(const Ogre::FrameEvent& evt)
{
}
