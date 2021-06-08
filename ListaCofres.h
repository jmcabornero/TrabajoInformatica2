#pragma once
#define MAX_COFRES 11
#include "Interaccion.h"
#include "Protagonista.h"
#include "Vector2D.h"
#include "Cofres.h"
class ListaCofres
{
private:
	Cofres* lista[MAX_COFRES];
	int numero;
public:
	ListaCofres();
	virtual ~ListaCofres();
	bool Agregar(Cofres* o);
	void Dibuja();
	void CrearCofres();
	void Transformacion(Protagonista*p);
	Cofres* operator[](int i);
	int getNumero() { return numero; };

};



