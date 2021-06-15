#pragma once
#include "Disparo.h"
#define MAX_DISPAROS 10000
#include "enemigo.h"
#include "Interaccion.h"
#include "Obstaculos.h"
#include "Protagonista.h"
#include "Vector2D.h"
#include "Enemigo.h"

class ListaDisparos
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();

	bool agregar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();

	void elimina(int index);
	void elimina(Disparo* d);

	void colision(Enemigo *e);
	int colision(Obstaculos* o);
	void colision(Protagonista *p);
	void Cooldown(Protagonista &p);
	void Disparar(Protagonista &p);

	
private:
	Disparo* Lista[MAX_DISPAROS];
	int num;
};
