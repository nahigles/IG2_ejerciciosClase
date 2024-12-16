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

class LucesSombras1 : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* mSM = nullptr;

    Ogre::SceneNode* mOgreheadNode = nullptr;

    // Nodes
    Ogre::SceneNode* nodePoint = nullptr;
    Ogre::SceneNode* nodeSpot1 = nullptr;
    Ogre::SceneNode* nodeSpot2 = nullptr;
    Ogre::SceneNode* nodeDir = nullptr;

public:
    LucesSombras1(SceneManager* sManager);
    void setupLucesSombras1();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
};

