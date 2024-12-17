#include "IG2App.h"

using namespace Ogre;
using namespace std;



bool IG2App::keyPressed(const OgreBites::KeyboardEvent& evt) {

	// ESC key finished the rendering...
	if (evt.keysym.sym == SDLK_ESCAPE) {
		getRoot()->queueEndRendering();
	}

	return true;
}

void IG2App::shutdown() {

	//delete clock; // Ej1
	//delete snowman; // Ej2
	//delete earthAndSun; // Ej3
	//delete airplane; // Ej4
	//delete lucesSombras1; // Ej5
	//delete matLucSom2; // Ej 6
	delete animaciones; // Ej 7
	//delete particulas; // Ej 8
	//delete multitexturas; // EJ 9
	delete shaders; // Ej 10

	mShaderGenerator->removeSceneManager(mSM);
	mSM->removeRenderQueueListener(mOverlaySystem);

	mRoot->destroySceneManager(mSM);

	delete mTrayMgr;  mTrayMgr = nullptr;
	delete mCamMgr; mCamMgr = nullptr;

	// do not forget to call the base 
	IG2ApplicationContext::shutdown();
}

void IG2App::setup(void) {

	// do not forget to call the base first
	IG2ApplicationContext::setup();

	// Create the scene manager
	mSM = mRoot->createSceneManager();

	// Register our scene with the RTSS
	mShaderGenerator->addSceneManager(mSM);

	mSM->addRenderQueueListener(mOverlaySystem);
	mTrayMgr = new OgreBites::TrayManager("TrayGUISystem", mWindow.render);
	mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
	addInputListener(mTrayMgr);

	// Adds the listener for this object
	addInputListener(this);

	// Ejercicio 1
	//clock = new Clock(mSM);
	//addInputListener(clock);

	// Ejercicio 2
	//snowman = new Snowman(mSM);
	//addInputListener(snowman);

	// Ejercicio 3
	//earthAndSun = new EarthAndSun(mSM);
	//addInputListener(earthAndSun);

	// Ejercicio 5
	//lucesSombras1 = new LucesSombras1(mSM);
	//addInputListener(lucesSombras1);

	// Ejercicio 6
	//matLucSom2 = new MaterialesLucesSombras2(mSM);
	//addInputListener(matLucSom2);

	// Ejercio 7
	animaciones = new Animaciones(mSM);
	addInputListener(animaciones);

	// Ejercicio 8
	//particulas = new SistemaParticulas(mSM);
	//addInputListener(particulas);

	// Ejercicio 9
	//multitexturas = new Multitexturas(mSM);
	//addInputListener(multitexturas);

	// Ejercicio 10
	//shaders = new Shaders(mSM);
	//addInputListener(shaders);

	setupScene();
}

void IG2App::setupScene(void) {

	//------------------------------------------------------------------------
	// Creating the camera

	Camera* cam = mSM->createCamera("Cam");
	cam->setNearClipDistance(1);
	cam->setFarClipDistance(10000);
	cam->setAutoAspectRatio(true);
	//cam->setPolygonMode(Ogre::PM_WIREFRAME);

	mCamNode = mSM->getRootSceneNode()->createChildSceneNode("nCam");
	mCamNode->attachObject(cam);

	mCamNode->setPosition(0, 0, 1000);
	mCamNode->lookAt(Ogre::Vector3(0, 0, 0), Ogre::Node::TS_WORLD);

	// and tell it to render into the main window
	Viewport* vp = getRenderWindow()->addViewport(cam);
	vp->setBackgroundColour(Ogre::ColourValue(0.25, 0.25, 0.25));

	// Camera manager
	mCamMgr = new OgreBites::CameraMan(mCamNode);
	addInputListener(mCamMgr);
	mCamMgr->setStyle(OgreBites::CS_ORBIT);


	//------------------------------------------------------------------------
	// Creating the light

	//mSM->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
	Light* luz = mSM->createLight("Luz");
	luz->setType(Ogre::Light::LT_DIRECTIONAL);
	luz->setDiffuseColour(0.75, 0.75, 0.75);

	mLightNode = mSM->getRootSceneNode()->createChildSceneNode("nLuz");
	//mLightNode = mCamNode->createChildSceneNode("nLuz");
	mLightNode->attachObject(luz);
	mLightNode->setDirection(Ogre::Vector3(0, -1, -1));

	//-----------------------------------------------------------------------
	// Creating the floor

	// Creamos plano
	//Ogre::MeshManager::getSingleton().createPlane("floor", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	//	Plane(Vector3::UNIT_Y, 0),
	//	300, 200, 200, 200, true, 1, 5, 5,
	//	Vector3::UNIT_Z);

	// Entidad y Nodo
	//Entity* ent = mSM->createEntity("Floor", "floor");
	//SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
	//floor->attachObject(ent);

	//------------------------------------------------------------------------
	// Creating Sinbad

	//Ogre::Entity* ent = mSM->createEntity("Sinbad.mesh");
	//mSinbadNode = mSM->getRootSceneNode()->createChildSceneNode("nSinbad");
	//mSinbadNode->attachObject(ent);

	//// Show bounding box
	//mSinbadNode->showBoundingBox(true);

	//// Set position of Sinbad
	////mSinbadNode->setPosition(x, y, z);

	//// Set scale of Sinbad
	//mSinbadNode->setScale(20, 20, 20);

	////mSinbadNode->yaw(Ogre::Degree(-45));
	////mSinbadNode->setVisible(false);    


	//-----------------------------------------------------------------------
	// Creating Ejercicioss de Clase

	// Ejercicio 1
	//clock->setupClock();

	// Ejercicio 2
	//snowman->setupSnowman();

	// Ejercicio 3
	//earthAndSun->setupEarthAndSun();

	// Ejercicio 4
	//SceneNode* airplaneNode = mSM->getRootSceneNode()->createChildSceneNode("nAirplane");
	//airplane = new Airplane({ 0,0,0 }, airplaneNode, mSM);
	//addInputListener(airplane);

	// Ejercicio 5
	//lucesSombras1->setupLucesSombras1();

	// Ejercicio 6
	//matLucSom2->setupMaterialesLucesSombras2();

	// Ejercicio 7
	animaciones->setupAnimaciones();

	// Ejercicio 8
	//particulas->setupParticulas();

	// Ejercicio 9
	//multitexturas->setupMultitexturas();

	// Ejercicio 10
	//shaders->setupShaders();
}


