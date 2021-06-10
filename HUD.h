#pragma once
#include "Vector2D.h"
#include <iostream>
#include <fstream>
#include "Protagonista.h"
#include <sstream>
using namespace std;
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
	void dibuja(char* mensaje);
	void dibuja(const char* mensaje);
	void mueve();
	void DibujaTienda(float camara_x, float camara_y);
	void DibujaTienda2(float camara_x, float camara_y);
	void DibujaTienda3(float camara_x, float camara_y);
	void DibujaTienda4(float camara_x, float camara_y);
	void DibujaTiendaMaster(Protagonista *p, float camara_x, float camara_y);
};

