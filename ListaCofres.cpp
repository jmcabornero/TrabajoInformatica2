#include "ListaCofres.h"

ListaCofres::ListaCofres()
{
	numero = 0;
	for (int i = 0;i < MAX_COFRES;i++)
		lista[i] = 0;
}

ListaCofres::~ListaCofres()
{

}

bool ListaCofres::Agregar(Cofres* o)
{
	for (int i = 0; i < numero; i++)
	{
		if (o == lista[i])
			return false;
	}
	if (numero < MAX_COFRES)
	{
		lista[numero++] = o;
	}

	else
		return false;
	return true;
}

void ListaCofres::Dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->Dibuja();
}

void ListaCofres::Colision(Protagonista* p, int n) //n=1 si obstaculo	n=2 si pinchos
{
	
}

void ListaCofres::CrearCofres()
{
	lista[0]=new Cofres(57, 117, 1);

}

Cofres* ListaCofres::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

