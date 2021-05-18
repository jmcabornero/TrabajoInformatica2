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
	void Dibuja(float x, float y);
	void Mueve(float t);
	void setTam(float anchura, float altura);
	void setVel(float vx, float vy);
}; 

