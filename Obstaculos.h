#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Vector2D.h"

class Obstaculos
{
private:
	float j, i;
public:
	Obstaculos(int x=0, int y=0);
	void Dibuja();
	Vector2D GetEsquina();
};

