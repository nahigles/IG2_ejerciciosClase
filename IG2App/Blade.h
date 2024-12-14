#pragma once
#include "IG2Object.h"
class Blade : public IG2Object
{
protected:
	SceneNode* palaNode = nullptr;
	SceneNode* ogreheadNode = nullptr;

	static const double BLADE_ANCHO;
	static const double BLADE_ALTO;
	static const double BLADE_LARGO;

public:
	Blade(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);

protected:
	virtual void init();
};

