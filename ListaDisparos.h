#pragma once
#include "Disparo.h"
#define MAX_DISPAROS 20

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

	//void colision();
private:
	Disparo* Lista[MAX_DISPAROS];
	int num;

};

