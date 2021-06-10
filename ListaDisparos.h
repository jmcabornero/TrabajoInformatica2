#pragma once
#include "Disparo.h"
#define MAX_DISPAROS 20
#include "enemigo.h"
#include "Interaccion.h"
#include "ListaEnemigos.h"
#include "Obstaculos.h"
#include "Protagonista.h"
#include "Vector2D.h"

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
	void colision(Obstaculos* o);
	void Cooldown(Protagonista &p);
	void Disparar(Protagonista p);
	//void DispararEnemigo(Enemigo e, Protagonista p);
	
private:
	Disparo* Lista[MAX_DISPAROS];
	int num;
	//float cooldawn;
	bool flag;
	
};
