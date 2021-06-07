#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Vector2D.h"

class Moneda
{
private:
	float j, i;
public:
	Moneda(int x = 0, int y = 0);
	void Dibuja(int n); //n=1 moneda verde   n=2 moneda roja
	Vector2D GetEsquina();
};

