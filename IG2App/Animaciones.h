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
#include <OgreKeyFrame.h>
#include <OgreSkeletonInstance.h>
#include <OgreBone.h>

using  namespace std;
using namespace Ogre;

class Animaciones : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* mSM = nullptr;

    // Sinbad and swords
    Ogre::SceneNode* sinbadNode = nullptr;
    Ogre::Entity* sinbadEnt;
    Ogre::Entity* swordLeftEnt;
    Ogre::Entity* swordRightEnt;

    // Flags to control the attached swords
    bool attachedLeftSword = false;
    bool attachedRightSword = false;

    // Lights
    Ogre::Light* spotLight1;
    Ogre::Light* spotLight2;
    Ogre::SceneNode* nodeSpot1 = nullptr;
    Ogre::SceneNode* nodeSpot2 = nullptr;
    int dynamicComponent = 0;

    // Animation state
    Ogre::AnimationState* animationState;

    // Animation states for Sinbad
    Ogre::AnimationState* animationStateDance;
    Ogre::AnimationState* animationStateRunBase;
    Ogre::AnimationState* animationStateRunTop;

    // Flags to control the animations
    bool isDancing = false;
    bool isRunning = false;

public:
    Animaciones(SceneManager* sManager);
    void setupAnimaciones();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
    virtual void frameRendered(const Ogre::FrameEvent& evt);
};

