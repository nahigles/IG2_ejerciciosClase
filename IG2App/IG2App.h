#ifndef __IG2App_H__
#define __IG2App_H__

#include "IG2ApplicationContext.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreTrays.h>
#include <OgreCameraMan.h>
#include <OgreEntity.h>
#include <OgreInput.h>
#include <SDL_keycode.h>
#include <OgreMeshManager.h>
#include <sstream>
#include <iostream>
#include <string>

#include "Clock.h"
#include "Snowman.h"
#include "EarthAndSun.h"
#include "Airplane.h"
#include "LucesSombras1.h"
#include "MaterialesLucesSombras2.h"
#include "Animaciones.h"

class IG2App : public  OgreBites::IG2ApplicationContext, OgreBites::InputListener{

public:
    explicit IG2App() : IG2ApplicationContext("IG2App") { };  // new -> setup()
    virtual ~IG2App() { };                                    // delete -> shutdown()
 
protected:
    virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
    virtual void setup();
    virtual void shutdown();
    virtual void setupScene();
    
    
    Ogre::SceneNode* mSinbadNode = nullptr;
      
    Ogre::SceneManager* mSM = nullptr;
    OgreBites::TrayManager* mTrayMgr = nullptr;
    
    Ogre::Light* light = nullptr;
    Ogre::SceneNode* mLightParent = nullptr;
    Ogre::SceneNode* mLightNode = nullptr;
    
    Ogre::SceneNode* mCamNode = nullptr;
    OgreBites::CameraMan* mCamMgr = nullptr;

    // Punteros Ejercicios clase
    Clock* clock = nullptr;
    Snowman* snowman = nullptr;
    EarthAndSun* earthAndSun = nullptr;
    Airplane* airplane = nullptr;
    LucesSombras1* lucesSombras1 = nullptr;
    MaterialesLucesSombras2* matLucSom2 = nullptr;
    Animaciones* animaciones = nullptr;
};

#endif
