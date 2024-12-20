#pragma once
#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreInput.h>
//#include <OgreMath.h>
#include <OgreFrameListener.h>
#include <OgreMeshManager.h>
#include <SDL_keycode.h>
#include <iostream>
#include <OgreParticleSystem.h>
#include <OgreBillboardSet.h>

using  namespace std;
using namespace Ogre;

class Shaders : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* mSM = nullptr;

    // Sinbad and swords
    Ogre::SceneNode* sinbadNode = nullptr;
    Ogre::Entity* sinbadEnt;

public:
    Shaders(SceneManager* sManager);
    void setupShaders();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
    virtual void frameRendered(const Ogre::FrameEvent& evt);
};

