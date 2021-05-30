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
	SpriteSequence sprite{ "imagenes/Player_reposo.png", 12 };
	SpriteSequence spriteR{ "imagenes/Player_derecha.png", 12 };
	SpriteSequence spriteL{ "imagenes/Player_izquierda.png", 12 };
	SpriteSequence spriteUp{ "imagenes/Player_arriba.png", 12 };
	SpriteSequence spriteDown{ "imagenes/Player_abajo.png", 12 };

	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
};