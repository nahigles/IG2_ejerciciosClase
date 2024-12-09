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

using  namespace std;
using namespace Ogre;

class Clock : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* sceneManager;

    // The clock
    Ogre::SceneNode* clockNode;
    Ogre::SceneNode* hoursNode;
    Ogre::SceneNode* handsNode;
    Ogre::SceneNode* hourHandNode;
    Ogre::SceneNode* minuteHandNode;
    Ogre::SceneNode* secondHandNode;

    Ogre::SceneNode* hourHandNodePositional;

    static const int CLOCK_RADIUS;

public:
	Clock(SceneManager* sManager);
    void setupClock();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
};

