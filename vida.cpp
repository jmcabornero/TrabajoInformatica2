#include "Vida.h"

Vida::~Vida() {}

Vida::Vida()
{
	setVida(100);
}

float Vida::getVida()
{
	return Ps;
}

void Vida::ModVida(int m)
{
	int aux = getVida() + m;
	setVida(aux);
	//cout << Ps << endl;
}

