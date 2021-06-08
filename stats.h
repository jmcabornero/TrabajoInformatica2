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

	float getVida() { return vida; }
	void setVida(float v) { vida = v; }
	float getDef() { return defensa; }
	void setDef(float d) { defensa = d; }
	float getAtack() { return ataque; }
	float getvel() { return vel; }
	float getcooldawn() { return cd; }
	//float getVida();
	void modDef(float m);
	void modAtack(float m);
	void modVel(float m);
	void ModVida(int i=1, float ataque=1);
	void modCooldawn(float cd1);
};

