#include "ListaEnemigos.h"
#include "Interaccion.h"
#include "ListaMonedas.h"
#include "ETSIDI.h"
#define _USE_MATH_DEFINES
#include <math.h>

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	for (int i = 0; i < 40; i++)
		lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos(){}

bool ListaEnemigos::agregar(Enemigo *e)
{
	if (numero < 40)
		lista[numero++] = e; // �ltimo puesto sin rellenar
	else
		return false; // capacidad m�xima alcanzada
	return true;
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaEnemigos::Perseguir(Protagonista p)
{
	for (int i = 0; i < numero; i++)
		if (lista[i]->getTipo()==2|| lista[i]->getTipo() == 3)
		lista[i]->Perseguir(p);
}

void ListaEnemigos::dano(ListaMonedas *listamonedas)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getVida() <= 0)
		{
			float posx = lista[i]->GetPosx();
			float posy = lista[i]->getPosy();
			float valor = ETSIDI::lanzaDado(10.0);
			if (valor <= 5)
				listamonedas->Agregar(new Moneda(posx, posy, 1));
			if((valor>5)&&(valor<6))
				listamonedas->Agregar(new Moneda(posx, posy, 2));
			eliminar(i);
		}
	}
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(0.025f);
}

void ListaEnemigos::destruirContenido()
{
	for (int i = 0; i < numero; i++) 
		delete lista[i];
	numero = 0;
}

Enemigo* ListaEnemigos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaEnemigos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::Disparar(ListaDisparos *ds)
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getTipo() == 1 || lista[i]->getTipo() == 3)
		{
			if (lista[i]->getFlag() == 0)
			{
				Vector2D e_pos = lista[i]->GetPos();
				Disparo* d = new Disparo();
				d->setP(2);
				d->setPos(e_pos.x, e_pos.y);
				lista[i]->setFlag(1);

				Vector2D vel = lista[i]->GetVel();
				float angulo = atan2(vel.y, vel.x);

				if((angulo < M_PI/4 )&& (angulo >-( M_PI / 4)))
					d->setVel(10, 0);
				if ((angulo > M_PI / 4) && (angulo <3 * (M_PI / 4)))
					d->setVel(0, 10);
				if (angulo < -3 * (M_PI / 4) || angulo > 3 * (M_PI / 4)) 
					d->setVel(-10, 0);
				if ((angulo > -3 * (M_PI / 4)) && (angulo <-  (M_PI / 4)))
					d->setVel(0, -10);

				cout << angulo;
				ds->agregar(d);
			}
		}
	}
}

void ListaEnemigos::CoolDown()
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getFlag() == 1)
		{
			Sleep(0.025);
			lista[i]->setCoolDown(lista[i]->getCoolDown() - 0.050);
			if (lista[i]->getCoolDown() <= 0)
			{
				lista[i]->setFlag(0);
				lista[i]->setCoolDown(1.0);
			}
		}
	}
	
}

void ListaEnemigos::kamikaze(Protagonista &p)
{
	for (int i = 0; i < numero; i++)
	{
		bool ix = Interaccion::colision(*(lista[i]), p);
		if (ix == 1)
		{
			if (lista[i]->getTipo() == 2 || lista[i]->getTipo() == 3)
			{
				p.ModVida(5);
				eliminar(i);
			}
		}
	}
}

