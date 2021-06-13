#include "ListaObstaculos.h"
#include <iostream>

ListaObstaculos::ListaObstaculos()
{
	numero = 0;
	for (int i = 0;i < MAX_OBSTACULOS;i++)
		lista[i] = 0;
}

ListaObstaculos::~ListaObstaculos()
{

}

bool ListaObstaculos::Agregar(Obstaculos* o)
{
	for (int i = 0; i < numero; i++)
	{
		if (o == lista[i])
			return false;
	}
	if (numero < MAX_OBSTACULOS)
		{
		lista[numero++] = o;
	}
		
	else
		return false;
	return true;
}

void ListaObstaculos::Dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->Dibuja();
}

void ListaObstaculos::Colision(Protagonista* p, int n) //n=1 si obstaculo	n=2 si pinchos
{
	Interaccion inter;
	bool aux=false;
	Vector2D pos = (*p).GetPos();
	Vector2D vel = (*p).GetVel();
	float velabs = 0;
	if (n ==1)
		velabs = (p->GetVelAbs()) / 6;
	if (n == 2)
		velabs = 1;
	for (int i = 0;i < numero;i++)
	{
		if (n == 1)
			aux = inter.colision((*p), *(lista[i]));
		if (n == 2)
			aux = inter.colisionpinchos((*p), *(lista[i]));
		if (aux)
		{
			if (vel.x>0)
				(*p).setPos(pos.x-velabs, pos.y);
			if (vel.x < 0)
				(*p).setPos(pos.x + velabs, pos.y);
			if (vel.y > 0)
				(*p).setPos(pos.x, pos.y- velabs);
			if (vel.y < 0)
				(*p).setPos(pos.x, pos.y + velabs);
			if ((vel.x > 0) && (vel.y > 0))
			{
				(*p).setPos(pos.x- velabs, pos.y - velabs);
			}
			if ((vel.x > 0) && (vel.y < 0))
			{
				(*p).setPos(pos.x- velabs, pos.y + velabs);
			}	
			if ((vel.x < 0) && (vel.y > 0))
			{
				(*p).setPos(pos.x + velabs, pos.y - velabs);
			}
			if ((vel.x < 0) && (vel.y < 0))
			{
				(*p).setPos(pos.x + velabs, pos.y + velabs);
			}
			if (n == 2) {
				p->ModVida(4);
				//p->setDinero(p->getDinero() + 1);
			}
		}
	}
}

void ListaObstaculos::Colision(Enemigo* e, int n) //n=1 si obstaculo	n=2 si pinchos
{
	Interaccion inter;
	bool aux = false;
	Vector2D pos = (*e).GetPos();
	Vector2D vel = (*e).GetVel();
	if(e->getBioma()==4)
	{
		for (int i = 0;i < numero;i++)
		{
			aux = inter.colision((*e), *(lista[i]));
			if (aux)
			{
				Vector2D vel=e->GetVel();
				e->setVelx(-vel.x);
				/*if (vel.x > 0)
					(*e).setPos(pos.x - velabs, pos.y);
				if (vel.x < 0)
					(*e).setPos(pos.x + velabs, pos.y);*/
			}
		}
		
	}
}

Obstaculos* ListaObstaculos::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaObstaculos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}