#include "Shaders.h"

Shaders::Shaders(SceneManager* sManager)
{
    mSM = sManager;
}

void Shaders::setupShaders()
{
    //------------------------------------------------------------------------
   // Creating the floor

    MeshManager::getSingleton().createPlane("floorShaders", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        Plane(Vector3::UNIT_Y, 0),
        500, 500, 200, 200, true, 1, 5, 5,
        Vector3::UNIT_Z);

    // Creating the plane
    Entity* ent = mSM->createEntity("exampleFloorShaders", "floorShaders");
    SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
    floor->attachObject(ent);

    // Material with stones (NO shader)
    ent->setMaterialName("example/stonesFloor");

    //------------------------------------------------------------------------
    // Creating Sinbad

    sinbadEnt = mSM->createEntity("Sinbad.mesh");
    sinbadNode = mSM->getRootSceneNode()->createChildSceneNode();
    sinbadNode->attachObject(sinbadEnt);
    sinbadNode->scale(12, 12, 12);
    sinbadNode->setPosition(0, 100, 0); // On the floor!
    sinbadNode->setInitialState();


    //------------------------------------------------------------------------
    // Skyplane

    //Creating a skyplane
    Ogre::Plane plane;
    plane.d = 1000;
    plane.normal = Ogre::Vector3::UNIT_Z;

    // Sky using multitexture
    mSM->setSkyPlane(true, plane, "example/sky", 20, 1, true, 0, 50, 50);

    // Sky using shaders here!!!



    //------------------------------------------------------------------------
    // Primer ejemplo de shader (esfera naranja)

    Entity* sphereEnt = mSM->createEntity("uv_sphere.mesh");
    SceneNode* sphereNode = mSM->getRootSceneNode()->createChildSceneNode();
    sphereNode->attachObject(sphereEnt);
    sphereNode->setPosition(Vector3(0, 100, 0));

    // Sphere with shaders here!!!
    sphereEnt->setMaterialName("example/shaderOrange");

}

bool Shaders::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	return true;
}

void Shaders::frameRendered(const Ogre::FrameEvent& evt)
{
}
