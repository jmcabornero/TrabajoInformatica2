#pragma once
#define MAX_COFRES 11
#include "Interaccion.h"
#include "Protagonista.h"
#include "Vector2D.h"
#include "Cofres.h"
#include <time.h>
#include "HUD.h"
#include "ETSIDI.h"
#include "freeglut.h"
class ListaCofres
{
private:
	Cofres* lista[MAX_COFRES];
	time_t tiempos[MAX_COFRES];
	int numero;
public:
	ListaCofres();
	virtual ~ListaCofres();
	bool Agregar(Cofres* o);
	void Dibuja(float posicion_ojo_x, float posicion_ojo_y);
	void CrearCofres();
	void Transformacion(Protagonista*p);
	Cofres* operator[](int i);
	int getNumero() { return numero; };
	HUD mensaje;
	void destruirContenido();

};



