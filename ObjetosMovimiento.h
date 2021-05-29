#pragma once
#include "Vector2D.h"

class ObjetosMovimiento
{
protected:
	Vector2D posicion, velocidad;
public:
	void setVel(float vx, float vy) { velocidad.x = vx; velocidad.y = vy; }
	void setPos(float x, float y) { posicion.x = x; posicion.y = y; }
	void setVelx(float vx) { velocidad.x = vx; }
	void setVely(float vy) { velocidad.y = vy; }
	Vector2D GetPos() { return posicion; }
	Vector2D GetVel() { return velocidad; }
	void mueve(float t);
};

