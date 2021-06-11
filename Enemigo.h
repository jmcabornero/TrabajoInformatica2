#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "stats.h"
#include "Protagonista.h"
#include <math.h>

using ETSIDI::SpriteSequence;

class Enemigo :public ObjetosMovimiento, public stats
{
private:
	char direccion;
	int tipo;
	int bioma;
public:
	Enemigo(float x, float y, int b=1, int t=1);
	virtual ~Enemigo();
	SpriteSequence sprite{ "imagenes/Player_arriba.png", 3 };
	SpriteSequence spriteR{ "imagenes/Player_derecha.png", 3 };
	SpriteSequence spriteL{ "imagenes/Player_izquierda.png", 3 };
	char getDir() { return direccion; }
	void setDir(char d) { direccion = d; }
	int getTipo() { return tipo; }
	void setTipo(int t) { tipo = t; }
	void Dibuja();
	int getBioma() { return bioma; }
	void setBioma(int b) { bioma = b; }
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void Perseguir(Protagonista p);
	friend class Interaccion;
	
};

