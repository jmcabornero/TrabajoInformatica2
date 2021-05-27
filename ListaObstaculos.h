#pragma once
#define MAX_OBSTACULOS 99999
#include "Obstaculos.h"

class ListaObstaculos
{
private:
	Obstaculos* lista[MAX_OBSTACULOS];
	int numero;


public:
	ListaObstaculos();
	virtual ~ListaObstaculos();
	bool Agregar(Obstaculos* o);
	void Dibuja();


};

