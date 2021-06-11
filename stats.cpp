#include "stats.h"


stats::~stats() {}

stats::stats()
{
	vida = 100;
	defensa = 1;
	ataque = 1;
	vel = 0;
	cd= 2.0;
	attackspeed = 1;
	dinero = 0;
	pociones = 0;
}

void stats::ModVida(int i, float ataque)
{
	float dano=0;
	if (i == 1)
	dano = (25.0 * ataque) / defensa;
	if (i == 2)
		dano = (35.0 * ataque) / defensa;
	if (i == 3)
		dano = (45.0 * ataque) / defensa;
	if (i == 4)
		dano = 10;
	if (i == 5)
		dano = 50;
	vida = vida - dano;
	if (getVida() < 0)setVida(0); 
	if (getVida() > 100)setVida(100);
	//cout << "vida: " << vida << endl;
}