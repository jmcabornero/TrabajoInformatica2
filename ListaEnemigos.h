#pragma once
#include "Enemigo.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "Interaccion.h"
#include "ListaMonedas.h"

class ListaEnemigos
{
private:
	Enemigo* lista[40];
	int numero;

public:
	ListaEnemigos();
	virtual ~ListaEnemigos();
	bool agregar(Enemigo *e);
	void dibuja();
	void mueve(float t);
	void dano(ListaMonedas *listamonedas);
	void eliminar(int index);
	void destruirContenido();
	int getNumero() { return numero; }
	void Perseguir(Protagonista p);
	friend class Interaccion;
	Enemigo* operator [](int i);
};

