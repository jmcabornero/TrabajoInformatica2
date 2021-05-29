#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"

using ETSIDI::SpriteSequence;

class Protagonista:public ObjetosMovimiento
{
private: 
	int vida;
public:
	Protagonista();
	SpriteSequence sprite{ "imagenes/Player_reposo.png", 5 };
	SpriteSequence spriteR{ "imagenes/Player_derecha.png", 5 };
	SpriteSequence spriteL{ "imagenes/Player_izquierda.png", 5 };
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void setVida(int n) { vida = n; }
	int getVida() { return vida; }
};