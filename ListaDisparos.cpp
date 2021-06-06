#include "ListaDisparos.h"
#include "Enemigo.h"
#include <iostream>
#include <windows.h>

ListaDisparos::ListaDisparos() {
	for (int i = 0; i < MAX_DISPAROS; i++)Lista[i] = 0;
	num = 0;
	flag = 0;
	cooldawn = 2.0;
}

ListaDisparos::~ListaDisparos() {}

bool ListaDisparos::agregar(Disparo *d) {
	if (num < MAX_DISPAROS) {
		Lista[num++] = d;
		flag = 1;
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
				(*e).ModVida(1, Lista[i]->getIdent());
				elimina(Lista[i]);
			}
	}
}

void ListaDisparos::colision(Obstaculos* o)
{
	for (int i = 0; i < num; i++)
	{
		bool x;
		x = Interaccion::colision(*(Lista[i]), *o);
		if (x == 1)
		{
			elimina(Lista[i]);
		}
	}
}
void ListaDisparos::Cooldawn() 
{
	if (flag==1)
	{
		Sleep(0.025);
		cooldawn = cooldawn - 0.050;
		if (cooldawn <= 0)
		{
			flag = 0;
			cooldawn = 1.0;
		}
		cout <<"-"<<cooldawn<<"-";
	}
}

void ListaDisparos::Disparar(Protagonista p)
{
	if (flag == 0)
	{
		Vector2D h_pos = p.GetPos();
		Disparo* d = new Disparo();
		d->setPos(h_pos.x, h_pos.y);

		switch (p.getDir()) {
		case 'd':
			d->setVel(10, 0);
			break;
		case 'a':
			d->setVel(-10, 0);
			break;
		case 'w':
			d->setVel(0, 10);
			break;
		case 's':
			d->setVel(0, -10);
			break;
		}
		agregar(d);
	};
}