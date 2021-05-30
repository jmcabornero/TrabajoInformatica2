#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "vida.h"

using ETSIDI::SpriteSequence;

class Enemigo :public ObjetosMovimiento
{
private:
	Vida vida;
	char direccion;
public:
	Enemigo(float x, float y);
	virtual ~Enemigo();
	SpriteSequence sprite{ "imagenes/Player_reposo.png", 5 };
	SpriteSequence spriteR{ "imagenes/Player_derecha.png", 5 };
	SpriteSequence spriteL{ "imagenes/Player_izquierda.png", 5 };
	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void ModVida(int m);
	int GetVida() { return vida.getVida(); };
	friend class Interaccion;
};

