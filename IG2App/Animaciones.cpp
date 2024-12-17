#include "Animaciones.h"

Animaciones::Animaciones(SceneManager* sManager)
{
	mSM = sManager;
}

void Animaciones::setupAnimaciones()
{

	//------------------------------------------------------------------------
	// Creating the floor

	MeshManager::getSingleton().createPlane("floorAnim", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Plane(Vector3::UNIT_Y, 0),
		1500, 1500, 200, 200, true, 1, 5, 5,
		Vector3::UNIT_Z);

	// Creating the plane
	Entity* ent = mSM->createEntity("exampleFloorAnim", "floorAnim");
	ent->setMaterialName("example/stonesFloor");
	SceneNode* floor = mSM->getRootSceneNode()->createChildSceneNode();
	floor->attachObject(ent);


	//------------------------------------------------------------------------
	// Creating Sinbad

	sinbadEnt = mSM->createEntity("Sinbad.mesh");
	sinbadNode = mSM->getRootSceneNode()->createChildSceneNode();
	sinbadNode->attachObject(sinbadEnt);
	sinbadNode->scale(5, 5, 5);
	sinbadNode->setPosition(0, 25, 0); // On the floor!
	sinbadNode->setInitialState();

	// Creating two swords
	swordLeftEnt = mSM->createEntity("Sword.mesh");
	swordRightEnt = mSM->createEntity("Sword.mesh");

	// Obtain the names of all the animations in Sinbad.mesh
	AnimationStateSet* aux = sinbadEnt->getAllAnimationStates();
	auto it = aux->getAnimationStateIterator().begin();
	while (it != aux->getAnimationStateIterator().end()) {
		auto s = it->first;
		++it;
		cout << "Animation name (Sinbad.mesh): " << s << endl;
	}

	// Obtain the names of all the bones in Sinbad.mesh
	SkeletonInstance* skeleton = sinbadEnt->getSkeleton();
	int numBones = skeleton->getNumBones();
	for (int i = 0; i < numBones; i++) {
		cout << "Bone name (Sinbad.mesh): " << skeleton->getBone(i)->getName() << endl;
	}


	//------------------------------------------------------------------------
	// Animation of Sinbad
	animationStateDance = sinbadEnt->getAnimationState("Dance"); //entity se construye sobre una malla
	animationStateRunBase = sinbadEnt->getAnimationState("RunBase");
	animationStateRunTop = sinbadEnt->getAnimationState("RunTop");

	// Set keyframes here...
	// Variables
	int movementLength = 50;
	Real duration = 16.0;
	Vector3 keyframePos(0, 0, 0);
	Real durStep = duration / 4.0;

	// Create the animation and track
	Animation* animation = mSM->createAnimation("sinbadWalking", duration);
	animation->setInterpolationMode(Ogre::Animation::IM_SPLINE);
	NodeAnimationTrack* track = animation->createNodeTrack(0);
	track->setAssociatedNode(sinbadNode);
	TransformKeyFrame* kf;

	Quaternion keepDir = Quaternion::IDENTITY;
	Quaternion rightDir = Quaternion(Degree(90), Vector3::UNIT_Y);
	Quaternion leftDir = Quaternion(Degree(90), Vector3::NEGATIVE_UNIT_Y);

	// Keyframe 0 (Init state)
	kf = track->createNodeKeyFrame(durStep * 0);
	kf->setTranslate(keyframePos);
	kf->setRotation(rightDir);
	// Keyframe 1: Go to the right
	kf = track->createNodeKeyFrame(durStep * 1);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	kf->setTranslate(keyframePos);
	kf->setRotation(rightDir * keepDir);
	// Keyframe 2: Go to the initial position
	kf = track->createNodeKeyFrame(durStep * 2);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_X * movementLength;
	kf->setTranslate(keyframePos);
	kf->setRotation(leftDir);
	// Keyframe 3: Go to the left
	kf = track->createNodeKeyFrame(durStep * 3);
	keyframePos += Ogre::Vector3::NEGATIVE_UNIT_X * movementLength;
	kf->setTranslate(keyframePos);
	kf->setRotation(leftDir * keepDir);
	// Keyframe 4: Go to the right (initital position)
	kf = track->createNodeKeyFrame(durStep * 4);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	kf->setTranslate(keyframePos);
	kf->setRotation(leftDir * keepDir);
	// Keyframe 5: Go to the right (initital position)
	kf = track->createNodeKeyFrame(durStep * 5);
	//keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	kf->setTranslate(keyframePos);
	kf->setRotation(rightDir);
	// Keyframe 6: Go to the right (initital position)
	kf = track->createNodeKeyFrame(durStep * 5);
	keyframePos += Ogre::Vector3::UNIT_X * movementLength;
	kf->setTranslate(keyframePos);
	kf->setRotation(rightDir*keepDir);

	// Our defined animation
	animationState = mSM->createAnimationState("sinbadWalking");
	animationState->setLoop(true);
	animationState->setEnabled(true);

	// Animations for running and dancing...
	// TODO...
}

bool Animaciones::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	// Running animation
	if (evt.keysym.sym == SDLK_r) {
		if (isRunning) {
			isRunning = false;

		}
		else {
			isRunning = true;
		}

		animationStateRunBase->setEnabled(isRunning);
		animationStateRunBase->setLoop(isRunning);
		animationStateRunTop->setEnabled(isRunning);
		animationStateRunTop->setLoop(isRunning);
	}

	// Dancing animation
	else if (evt.keysym.sym == SDLK_d) {
		if (isDancing) {
			isDancing = false;

		}
		else {
			isDancing = true;

		}
		animationStateDance->setEnabled(isDancing);
		animationStateDance->setLoop(isDancing);
	}

	// Attach/Dettach left sword
	if (evt.keysym.sym == SDLK_q) {
		// Si tiene la espada la quito
		if (attachedLeftSword) {
			sinbadEnt->detachObjectFromBone(swordLeftEnt);
			attachedLeftSword = false;
		}
		// Si no la tiene se la pongo
		else {
			sinbadEnt->attachObjectToBone("Handle.L", swordLeftEnt);
			attachedLeftSword = true;
		}
	}
	// Attach/Dettach right sword
	else if (evt.keysym.sym == SDLK_e) {
		// Si tiene la espada la quito
		if (attachedRightSword) {
			sinbadEnt->detachObjectFromBone(swordRightEnt);
			attachedRightSword = false;
		}
		// Si no la tiene se la pongo
		else {
			sinbadEnt->attachObjectToBone("Handle.R", swordRightEnt);
			attachedRightSword = true;
		}
	}

	return true;
}

void Animaciones::frameRendered(const Ogre::FrameEvent& evt)
{
	// Example of numeric value animation (lights)
	//------------------------------------------------------------------------

//    dynamicComponent = (dynamicComponent + ((int) (evt.timeSinceLastFrame * 1000))) % 3000;
//    spotLight1->setDiffuseColour(1.0f, dynamicComponent/3000.0, 0.0f);
//    spotLight2->setDiffuseColour(1.0f, 0.0f, dynamicComponent/3000.0);


	// Example of scene node animation (Sinbad)
	//------------------------------------------------------------------------
	//sinbadNode->yaw(Ogre::Degree(30 * evt.timeSinceLastFrame));


	// Example of NodeAnimationTrack
	//------------------------------------------------------------------------
	animationState->addTime(evt.timeSinceLastFrame);


	// Example of Sinbad's animation (running and dancing)
	//------------------------------------------------------------------------

	if (isDancing)
		animationStateDance->addTime(evt.timeSinceLastFrame);
	else if (isRunning) {
		animationStateRunBase->addTime(evt.timeSinceLastFrame);
		animationStateRunTop->addTime(evt.timeSinceLastFrame);
	}
}
