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
public:
	stats();
	virtual ~stats();

	float getVida() { return vida; };
	float getDef() { return defensa; };
	float getAtack() { return ataque; };
	float getvel() { return vel; };
	//float getVida();
	void modDef(float m);
	void modAtack(float m);
	void modVel(float m);
	void ModVida(float ataque, int i);
};

