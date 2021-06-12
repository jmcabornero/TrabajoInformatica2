#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetosMovimiento.h"
#include "Protagonista.h"
using ETSIDI::SpriteSequence;

class Disparo:public ObjetosMovimiento
{
public:
	SpriteSequence disparo_dcha{ "imagenes/disparo1_derecha.png", 3 };
	SpriteSequence disparo_izda{ "imagenes/disparo1_izquierda.png", 3 };
	SpriteSequence disparo_up{ "imagenes/disparo1_arriba.png", 3 };
	SpriteSequence disparo_down{ "imagenes/disparo1_abajo.png", 3 };
	//SpriteSequence estela;
	Disparo(int i, float a);
	virtual ~Disparo();
private:
	float radio;
	int ident;
	int p; //nos sirve para identificar quien realiza el disparo (1::personaje; 2::Enemigos)
	float ataque;
public:
	void setRadio(float r) { radio = r; }
	float getRadio() { return radio; }
	void dibuja();
	void mueve(float t);
	int getIdent() { return ident; };
	void setIdent(int i) { ident = i; }
	void setP(int m) { p = m; };
	int getP() { return p; }
	void setAtaque(float a) { ataque = a; }
	float getAtaque() { return ataque; }
};

