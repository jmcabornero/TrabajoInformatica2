#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Vector2D.h"

class Cofres
{
private:
	float j, i;
	int tipo; //1 si esta cerrado 2 si esta abierto
public:
	Cofres(int x = 0, int y = 0, int t=0);
	void Dibuja();
	Vector2D GetEsquina();
};

