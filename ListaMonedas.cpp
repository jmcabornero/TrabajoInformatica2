#include "ListaMonedas.h"
#include <iostream>

ListaMonedas::ListaMonedas()
{
	numero = 0;
	for (int i = 0;i < MAX_MONEDAS;i++)
		lista[i] = 0;
}

ListaMonedas::~ListaMonedas()
{

}

bool ListaMonedas::Agregar(Moneda* o)
{
	for (int i = 0; i < numero; i++)
	{
		if (o == lista[i])
			return false;
	}
	if (numero < MAX_MONEDAS)
	{
		lista[numero++] = o;
	}

	else
		return false;
	return true;
}

void ListaMonedas::Dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->Dibuja();
}

void ListaMonedas::Colision(Protagonista* p)  //se elimina la rupia y se suma dinero a la cartera
{
	Interaccion inter;
	for (int i = 0;i < numero;i++)
	{
		if (inter.colision(*p, *(lista[i])))
			eliminar(i);
	}
}

Moneda* ListaMonedas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaMonedas::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}