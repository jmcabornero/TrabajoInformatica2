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
	for (int i = 0;i < MAX_COFRES;i++)
	{
		lista[i]->Dibuja();
	}
		
}

void ListaCofres::CrearCofres()
{
	lista[0]=new Cofres(57.0f, 117.0f, 1);
	lista[1] = new Cofres(42.0f, 71.0f, 1);
	lista[2] = new Cofres(7.0f, 71.0f, 1);
	lista[3] = new Cofres(85.0f, 2.0f, 1);
	lista[4] = new Cofres(94.0f, 2.0f, 1);
	lista[5] = new Cofres(136.0f, 26.0f, 1);
	lista[6] = new Cofres(135.0f, 40.0f, 1);
	lista[7] = new Cofres(137.0f, 58.0f, 1);
	lista[8] = new Cofres(184.0f, 55.0f, 1);
	lista[9] = new Cofres(195.0f, 55.0f, 1);
	lista[10] = new Cofres(183.0f, 87.0f, 1);
}

Cofres* ListaCofres::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}

void ListaCofres::Transformacion(Protagonista *p)
{
	Interaccion inter;
	int tipo;
	for (int i = 0;i < MAX_COFRES;i++)
	{
		tipo = lista[i]->GetTipo();
		if ((inter.colision(*p, (*lista[i])))&&(tipo==1))
		{
			lista[i]->SetTipo(2);
			
		}
	}
}
