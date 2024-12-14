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
#include <OgreCameraMan.h>
#include <OgreTrays.h>

using  namespace std;
using namespace Ogre;

class EarthAndSun : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* sceneManager;

    // Earth and sun
    Ogre::SceneNode* sun = nullptr;
    Ogre::SceneNode* earth = nullptr;
    Ogre::SceneNode* earthFake = nullptr;

    const static int EarthDistance;
    int alpha;

public:
	EarthAndSun(SceneManager* sManager);
    void setupEarthAndSun();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
};

