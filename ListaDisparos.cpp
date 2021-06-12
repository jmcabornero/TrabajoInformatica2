#include "ListaDisparos.h"
#include <iostream>
#include <windows.h>

ListaDisparos::ListaDisparos() {
	for (int i = 0; i < MAX_DISPAROS; i++)Lista[i] = 0;
	num = 0;
	//flag = 0;
	//cooldawn = 1.0;
}

ListaDisparos::~ListaDisparos() {}

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
		if (Lista[i]->getP() == 1)
		{
			bool x;
			x = Interaccion::colision(*(Lista[i]), *e);
			if (x == 1)
			{
				(*e).ModVida(Lista[i]->getIdent(), Lista[i]->getAtaque());
				elimina(Lista[i]);
			}
		}
	}
}

void ListaDisparos::colision(Protagonista *e)
{
	for (int i = 0; i < num; i++)
	{
		if (Lista[i]->getP() == 2)
		{
			bool x;
			x = Interaccion::colision(*(Lista[i]), *e);
			if (x == 1)
			{
				(*e).ModVida(Lista[i]->getIdent(), Lista[i]->getAtaque());
				elimina(Lista[i]);
			}
		}
	}
}

void ListaDisparos::colision(Obstaculos* o)
{
	for (int i = 0; i < num; i++)
	{
		bool x;
		x = Interaccion::colision(*(Lista[i]), *o);
		int tip = o->GetTipo();
		if (x == 1)
		{
			if (tip == 2)
				delete o;
			if (tip == 3)
				delete o;
			elimina(Lista[i]); /////////
		}
	}
}
void ListaDisparos::Cooldown(Protagonista &p)
{
	if (p.getFlag() == 1)
	{
		Sleep(0.025);
		p.setCoolDown(p.getCoolDown() - 0.050);
		if (p.getCoolDown() <= 0)
		{
			p.setFlag(0);
			p.setCoolDown(1.0/p.getAttackspeed());
		}
		//cout << "-" << p.getCoolDown() << "-";
	}
}

void ListaDisparos::Disparar(Protagonista &p)
{
	if (p.getFlag() == 0)
	{
		Vector2D h_pos = p.GetPos();
		Disparo* d = new Disparo(p.getTdis(),p.getAttack());
		d->setPos(h_pos.x, h_pos.y);
		d->setP(1);
		p.setFlag(1);
		
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



