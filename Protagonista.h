#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Protagonista
{
private: 
	Vector2D posicion, velocidad;
public:
	Protagonista();
	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	void Dibuja();
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void setVel(float vx, float vy);
	void setPos(float x, float y);
	void setVelx(float vx);
	void setVely(float vy);
	Vector2D GetPos();
	Vector2D GetVel();
}; 

