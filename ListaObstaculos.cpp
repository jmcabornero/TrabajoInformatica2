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