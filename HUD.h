#pragma once
#include "Vector2D.h"
class HUD
{
public:
	HUD();
	virtual ~HUD();
private:
	float alto;
	float ancho;
	Vector2D pos;
public:
	//sets y gets
	void setAlto(float h) { alto = h; }
	void setAncho(float a) { ancho = a; }
	void setPos(Vector2D posicion) { pos = posicion; }
	void setPos(float x, float y) { pos.x = x; pos.y = y; }
	float getAlto() { return alto; }
	float getAncho() { return ancho; }
	Vector2D getPos() { return pos; }
	//dibujo y movimiento en la pantalla
	void dibuja();
	void mueve();

};

