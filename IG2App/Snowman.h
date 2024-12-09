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

class Snowman : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* sceneManager;

    // The snowman
    Ogre::SceneNode* snowman;
    Ogre::SceneNode* head;
    Ogre::SceneNode* body;
    Ogre::SceneNode* leftEye;
    Ogre::SceneNode* rightEye;
    Ogre::SceneNode* nose;
    Ogre::SceneNode* mouth;
    Ogre::SceneNode* bellyButton;

public:
	Snowman(SceneManager* sManager);
    void setupSnowman();
};

