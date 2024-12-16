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

class MaterialesLucesSombras2 : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* mSM = nullptr;

    Ogre::SceneNode* mOgreheadNode = nullptr;

    SceneNode* directionalLightNode = nullptr;

    SceneNode* esferaNode = nullptr;

public:
    MaterialesLucesSombras2(SceneManager* sManager);
    void setupMaterialesLucesSombras2();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
};

