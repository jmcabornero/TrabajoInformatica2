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

void ListaObstaculos::Colision(Protagonista* p)
{
	Interaccion inter;
	Vector2D pos = (*p).GetPos();
	Vector2D vel = (*p).GetVel();
	for (int i = 0;i < numero;i++)
	{
		if (inter.colision((*p), *(lista[i])))
		{
			if (vel.x>0)
				(*p).setPos(pos.x-0.15, pos.y);
			if (vel.x < 0)
				(*p).setPos(pos.x + 0.15, pos.y);
			if (vel.y > 0)
				(*p).setPos(pos.x, pos.y-0.15);
			if (vel.y < 0)
				(*p).setPos(pos.x, pos.y + 0.15);
			if ((vel.x > 0) && (vel.y > 0))
			{
				(*p).setPos(pos.x-0.15, pos.y - 0.15);
			}
			if ((vel.x > 0) && (vel.y < 0))
			{
				(*p).setPos(pos.x-0.15, pos.y + 0.15);
			}	
			if ((vel.x < 0) && (vel.y > 0))
			{
				(*p).setPos(pos.x + 0.15, pos.y - 0.15);
			}
			if ((vel.x < 0) && (vel.y < 0))
			{
				(*p).setPos(pos.x + 0.15, pos.y + 0.15);
			}
		}
	}
}