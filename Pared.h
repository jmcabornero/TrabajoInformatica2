#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{
private:
	Vector2D limite1, limite2;
	ColorRGB color;
public:
	Pared();
	void Dibuja();
	virtual ~Pared();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia(Vector2D punto, Vector2D* direccion = 0);

	friend class Interaccion;
};

