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
	SpriteSequence spriteR{ "imagenes/duende/GoblinSlingerRightRun.png", 6 };
	SpriteSequence spriteL{ "imagenes/duende/GoblinSlingerLeftRun.png", 6 };
	SpriteSequence spriteUp{ "imagenes/duende/GoblinSlingerUpRun.png", 6 };
	SpriteSequence spriteDown{ "imagenes/duende/GoblinSlingerDownRun.png", 6 };
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

