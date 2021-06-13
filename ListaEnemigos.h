#pragma once
#define MAX_ENEMIGOS 297
#include "Enemigo.h"
#include "Disparo.h"
#include "Interaccion.h"
#include "ListaMonedas.h"
#include "ListaDisparos.h"
#include "Protagonista.h"

class ListaEnemigos
{
private:
	Enemigo* lista[MAX_ENEMIGOS];
	int numero;
	bool FlagBoss1;
	bool FlagBoss2;
	bool FlagBoss3;
public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	bool agregar(Enemigo *e);
	void dibuja();
	void mueve(float t);
	void dano(ListaMonedas *listamonedas);
	void eliminar(int index);
	void destruirContenido();
	void Disparar(ListaDisparos *ds);
	int getNumero() { return numero; }
	void Perseguir(Protagonista p);
	void CoolDown();
	friend class Interaccion;
	Enemigo* operator [](int i);
	void kamikaze(Protagonista &p);
	void distProta(Protagonista p);
	void movBoss();

	void especialBoss();
};