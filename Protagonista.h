#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "vida.h"


using ETSIDI::SpriteSequence;

class Protagonista:public ObjetosMovimiento
{
private:
	Vida vida;
	char direccion;
public:
	Protagonista();
	SpriteSequence sprite{ "imagenes/Player_reposo.png", 5 };
	SpriteSequence spriteR{ "imagenes/Player_derecha.png", 5 };
	SpriteSequence spriteL{ "imagenes/Player_izquierda.png", 5 };
	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
};