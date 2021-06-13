#pragma once
#define MAX_OBSTACULOS 99999
#include "Obstaculos.h"
#include "ETSIDI.h"
#include "Protagonista.h"
#include "Interaccion.h"

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
	void Colision(Protagonista* p,int n);
	void Colision(Enemigo* e, int n);
	Obstaculos* operator[](int i);
	int getNumero() { return numero; };
	void destruirContenido();
};

