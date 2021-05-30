#include "ListaDisparos.h"
#include "Enemigo.h"
#include <iostream>

ListaDisparos::ListaDisparos() {
	for (int i = 0; i < MAX_DISPAROS; i++)Lista[i] = 0;
	num = 0;
}

ListaDisparos::~ListaDisparos() {

}

bool ListaDisparos::agregar(Disparo *d) {
	if (num < MAX_DISPAROS) {
		Lista[num++] = d;
		return true;
	}
	else {
		std::cout << "numero maximo de disparos alcanzado (20)" << std::endl;
		return false;
	}
}

void ListaDisparos::destruirContenido() {
	for (int i = 0; i < num; i++)delete Lista[i];
}

void ListaDisparos::mueve(float t) {
	for (int i = 0; i < num; i++)Lista[i]->mueve(t);
}

void ListaDisparos::dibuja() {
	for (int i = 0; i < num; i++)Lista[i]->dibuja();
}

void ListaDisparos::elimina(int index) {
	if ((index < 0) || (index >= num))return;
	delete Lista[index];
	num--;
	for (int i = index; i < num; i++)Lista[i] = Lista[i + 1];
}

void ListaDisparos::elimina(Disparo* d) {
	for (int i = 0; i < num; i++) {
		if (Lista[i] == d) {
			elimina(i);
			return;
		}
	}
}

void ListaDisparos::colision(Enemigo *e)
{
	for (int i = 0; i < num; i++)
	{
			bool x;
			x = Interaccion::colision(*(Lista[i]), *e);
			if (x == 1)
			{
				elimina(Lista[i]);
				(*e).ModVida(-20);
			}
	}
}