#include "stats.h"


stats::~stats() {}

stats::stats()
{
	vida = 100;
	defensa = 1;
	ataque = 1;
	vel = 0;
}

void stats::ModVida(float ataque, int i)
{
	float dano;
	if (i == 1)
	dano = (25.0 * ataque) / defensa;
	if (i == 2)
		dano = (35.0 * ataque) / defensa;
	if (i == 3)
		dano = (45.0 * ataque) / defensa;
	if (i == 4)
		dano = -50;

	vida = vida - dano;
	cout << vida;
}