#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>
#include <OgreEntity.h>
#include <OgreSkeletonInstance.h>
#include <OgreBone.h>
#include <OgreKeyFrame.h>
#include <OgreBillboardSet.h>
#include <OgreParticleSystem.h>
#include <sstream>
#include <iostream>
#include <string>
#include <OgreMovablePlane.h>
#include <OgreRenderTargetListener.h>
#include <OgreRenderTexture.h>
#include <OgreTextureManager.h>
#include <OgreHardwarePixelBuffer.h>
#include <OgreSubEntity.h>
#include <OgreTechnique.h>

using  namespace std;
using namespace Ogre;

class Multitexturas : public OgreBites::InputListener
{
protected:
    // Scene Manager
    SceneManager* mSM = nullptr;

    // Sinbad and swords
    Ogre::SceneNode* sinbadNode = nullptr;
    Ogre::Entity* sinbadEnt;

public:
    Multitexturas(SceneManager* sManager);
    void setupMultitexturas();

protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
    virtual void frameRendered(const Ogre::FrameEvent& evt);
    //virtual void preRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
    //virtual void postRenderTargetUpdate(const Ogre::RenderTargetEvent& evt);
};

