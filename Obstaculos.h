#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Vector2D.h"

class Obstaculos
{
private:
	float j, i;
	int tipo; //1 si es normal, 2 si es la barrera roja y 3 si son las piedras
public:
	Obstaculos(int x=0, int y=0, int tip=0);
	void Dibuja();
	Vector2D GetEsquina();
	int GetTipo() { return tipo; }
};

