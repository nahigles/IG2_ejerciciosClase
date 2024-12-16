#pragma once
#include "IG2Object.h"
#include "Helix.h"
class Airplane : public IG2Object
{
protected:
	IG2Object* alaDerecha = nullptr;
	IG2Object* alaIzquierda = nullptr;
	IG2Object* cuerpo = nullptr;
	SceneNode* timonNode = nullptr;
	SceneNode* pilotoNode = nullptr;
	Helix* heliceDerecha = nullptr;
	Helix* heliceIzquierda = nullptr;

	static const double CUERPO_ANCHO;
	static const double CUERPO_ALTO;
	static const double CUERPO_LARGO;

	static const double ALA_ANCHO;
	static const double ALA_ALTO;
	static const double ALA_LARGO;

public:
	Airplane(Vector3 initPos, SceneNode* node, SceneManager* sceneMng);
	virtual ~Airplane() { delete heliceDerecha; heliceDerecha = nullptr; delete heliceIzquierda; heliceIzquierda = nullptr; };

protected:
	virtual void init() override;

	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);  // InputListener
};

