#include "Vida.h"

Vida::~Vida() {}

Vida::Vida()
{
	Ps = 100;
}

float Vida::getVida()
{
	return Ps;
}

void Vida::ModVida(int m)
{
	Ps = Ps + m;
	cout << Ps;
}

