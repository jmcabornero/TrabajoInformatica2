#pragma once
#include "Enemigo.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "Interaccion.h"

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
	void dano();
	void eliminar(int index);
	void destruirContenido();
	int getNumero() { return numero; }
	friend class Interaccion;
	Enemigo* operator [](int i);
};

