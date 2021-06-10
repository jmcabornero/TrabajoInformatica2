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
	float dinero;
	float pociones;
public:
	stats();
	virtual ~stats();
	float getVida() { return vida; }
	void setVida(float v) { vida = v; }
	float getDef() { return defensa; }
	void setDef(float d) { defensa = d; }
	float getAttack() { return ataque; }
	void setAttack(float a) { ataque = a; }
	float getVel() { return vel; }
	float getCoolDown() { return cd; }
	void setCoolDown(float c) { cd = c; }
	void modVel(float m) { vel = m; }
	void ModVida(int i = 1, float ataque = 1);
	void setDinero(int d) { dinero = d; }
	float getDinero() { return dinero; }
	float getAttackspeed() { return attackspeed; }
	void setAttackspeed(float as) { attackspeed = as; }
	float getPociones() { return pociones; }
	void setPociones(float p) { pociones = p; }
};