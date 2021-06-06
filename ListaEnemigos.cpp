#include "ListaEnemigos.h"
#include "Interaccion.h"

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
		lista[numero++] = e; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaEnemigos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaEnemigos::dano()
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getVida() <= 0)
		{
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
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas
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

