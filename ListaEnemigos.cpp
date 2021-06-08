#include "ListaEnemigos.h"
#include "Interaccion.h"
#include "ListaMonedas.h"

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
			{
				listamonedas->Agregar(new Moneda(posx, posy, 1));
			}
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
	for (int i = 0; i < numero; i++) // destrucci�n de esferas contenidas
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

