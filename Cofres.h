#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Vector2D.h"

class Cofres
{
private:
	float i, j;
	int tipo; //1 si esta cerrado 2 si esta abierto
public:
	Cofres(float x = 0, float y = 0, int t = 1);
	void Dibuja();
	void SetTipo(int a);
	int GetTipo();
	Vector2D GetEsquina();
};

