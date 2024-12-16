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

class SistemaParticulas : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* mSM = nullptr;

    // Sinbad and swords
    Ogre::SceneNode* sinbadNode = nullptr;
    Ogre::Entity* sinbadEnt;

    // Sistema de particulas
    SceneNode* mPSNode = nullptr;
    ParticleSystem* pSys = nullptr;

    SceneNode* mPSNode2 = nullptr;
    ParticleSystem* pSys2 = nullptr;

    // Esfera
    SceneNode* centerNode = nullptr;
    SceneNode* esferaNode = nullptr;

public:
    SistemaParticulas(SceneManager* sManager);
    void setupParticulas();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
    virtual void frameRendered(const Ogre::FrameEvent& evt);
};

