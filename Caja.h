#pragma once
#include "freeglut.h"
class Caja
{
private:
	
public:
	Caja();
	void Dibuja();
	void Dibuja2();
	virtual ~Caja();

	friend class Interaccion;
};
