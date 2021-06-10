#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Vector2D.h"

class Moneda
{
private:
	float j, i;
	int tipo;
public:
	Moneda(int x = 0, int y = 0, int t=1);
	void Dibuja(); //n=1 moneda verde   n=2 moneda roja
	Vector2D GetEsquina();
	int GetTipo();
};

