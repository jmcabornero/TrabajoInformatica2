#pragma once

#include <iostream>
using namespace std;

class Vida
{
private:
	int Ps;
public:
	Vida();
	virtual ~Vida();
	float getVida();
	void ModVida(int m);
	void setVida(int v) { Ps = v; }
};

