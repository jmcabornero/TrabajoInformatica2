#pragma once
#include "Pared.h" 

class Caja
{
private:
	Pared suelo, techo, pared_izq, pared_dcha;
public:
	Caja();
	void Dibuja();
	virtual ~Caja();

	friend class Interaccion;
	int a;
};
