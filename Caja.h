#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"



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
