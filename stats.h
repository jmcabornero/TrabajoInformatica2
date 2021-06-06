#pragma once

#include <iostream>
using namespace std;


class stats
{
protected:
	float vida;
	float defensa;
	float ataque;
	float vel;
	float cd;
	float attackspeed;
public:
	stats();
	virtual ~stats();

	float getVida() { return vida; };
	float getDef() { return defensa; };
	float getAtack() { return ataque; };
	float getvel() { return vel; };
	float getcooldawn() { return cd; };
	//float getVida();
	void modDef(float m);
	void modAtack(float m);
	void modVel(float m);
	void ModVida(float ataque=1, int i=1);
	void modCooldawn(float cd1);
};

