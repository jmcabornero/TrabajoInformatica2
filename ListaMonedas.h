#pragma once
#define MAX_MONEDAS 999
#include "ETSIDI.h"
#include "Protagonista.h"
#include "Interaccion.h"
#include "Moneda.h"

class ListaMonedas
{
private:
	Moneda* lista[MAX_MONEDAS];
	int numero;

public:
	ListaMonedas();
	virtual ~ListaMonedas();
	bool Agregar(Moneda* o);
	void Dibuja();
	void Colision(Protagonista* p);
	Moneda* operator[](int i);
	int getNumero() { return numero; };

};


