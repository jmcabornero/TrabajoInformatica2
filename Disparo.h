#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "Protagonista.h"
using ETSIDI::SpriteSequence;

class Disparo:public ObjetosMovimiento
{
public:
	SpriteSequence sprite{ "imagenes/Disparo1.png", 3 };
	//SpriteSequence estela;
	Disparo();
	virtual ~Disparo();
private:
	float radio;
public:
	void setRadio(float r) { radio = r; }
	float getRadio() { return radio; }
	void dibuja();
	void mueve(float t);
};

