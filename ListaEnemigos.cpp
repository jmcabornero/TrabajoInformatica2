#include "ListaEnemigos.h"
#include "Interaccion.h"
#include "ListaMonedas.h"
#include "ETSIDI.h"
#define _USE_MATH_DEFINES
#include <math.h>

ListaEnemigos::ListaEnemigos()
{
	numero = 0;
	FlagBoss1 = 1;
	FlagBoss2 = 1;
	FlagBoss3 = 1;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;
}

ListaEnemigos::~ListaEnemigos(){}

bool ListaEnemigos::agregar(Enemigo *e)
{
	if (numero < MAX_ENEMIGOS)
		lista[numero++] = e; // ?ltimo puesto sin rellenar
	else
		return false; // capacidad m?xima alcanzada
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
		if ((lista[i]->getVida() <= 0)&&(lista[i]->getBioma()!=4))
		{
			ETSIDI::play("sonidos/muerteEnemigo.mp3");
			float posx = lista[i]->GetPosx();
			float posy = lista[i]->getPosy();
			float valor = ETSIDI::lanzaDado(10.0);
			if (valor <= 6)
				listamonedas->Agregar(new Moneda(posx, posy, 1));
			if(valor>6)
				listamonedas->Agregar(new Moneda(posx, posy, 2));
			eliminar(i);
		}
	}
}

void ListaEnemigos::mueve(float t)
{
	for (int i = 0; i < numero; i++) {
		lista[i]->mueve(t);
	}
		
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
		if ((lista[i]->getTipo() == 1 || lista[i]->getTipo() == 3) && lista[i]->getBioma() != 4)
		{
			if (lista[i]->getFlag() == 0 && lista[i]->getFlagDist()==1)
			{
				Vector2D e_pos = lista[i]->GetPos();
				Disparo* d = new Disparo(1, lista[i]->getAttack());
				d->setP(2);
				d->setPos(e_pos.x, e_pos.y);
				lista[i]->setFlag(1);

				Vector2D vel = lista[i]->GetVel();
				

				if((lista[i]->getAngulo() < M_PI/4 )&& (lista[i]->getAngulo() >-( M_PI / 4)))
					d->setVel(10, 0);
				if ((lista[i]->getAngulo() > M_PI / 4) && (lista[i]->getAngulo() <3 * (M_PI / 4)))
					d->setVel(0, 10);
				if (lista[i]->getAngulo() < -3 * (M_PI / 4) || lista[i]->getAngulo() > 3 * (M_PI / 4))
					d->setVel(-10, 0);
				if ((lista[i]->getAngulo() > -3 * (M_PI / 4)) && (lista[i]->getAngulo() <-  (M_PI / 4)))
					d->setVel(0, -10);

					
				//cout << angulo;
				ds->agregar(d);
			}
		}
		if (lista[i]->getBioma() == 4)
		{

			if (lista[i]->getFlag() == 0 && lista[i]->getFlagDist() == 1)
			{
				Vector2D e_pos = lista[i]->GetPos();

				for (int j = 0; j < 4; j++)
				{
					Disparo* d = new Disparo(1, lista[i]->getAttack());
					d->setP(2);
					d->setPos(e_pos.x, e_pos.y);
					lista[i]->setFlag(1);
					switch (j)
					{
					case 0: 
						d->setVel(10, 0);
						break;
					case 1:
						d->setVel(0, 10);
						break;
					case 2:
						d->setVel(-10, 0);
						break;
					case 3:
						d->setVel(0, -10);
						break;

					}
					ds->agregar(d);
				}
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
				lista[i]->setCoolDown(4.0);
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

void ListaEnemigos::distProta(Protagonista p)
{
	for (int i = 0; i < numero; i++)
		lista[i]->distProta(p);
}

void ListaEnemigos::especialBoss()
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getBioma() == 4)
		{
			float v = lista[i]->getVida();
			int j;
			Vector2D pos = lista[i]->GetPos();
			if (FlagBoss1 && v <= 50)
			{
				
				Enemigo *e1 = new Enemigo(172,115,3,3);
				
				Enemigo* e2 = new Enemigo(167,115, 3, 3);

				agregar(e1); 
				agregar(e2);
				FlagBoss1 = 0;
			}
			if (FlagBoss2 && v <= 25)
			{
				
				Enemigo* e3 = new Enemigo(172, 115,3,3);
				
				Enemigo* e4 = new Enemigo(167, 115, 3, 3);

				agregar(e3);
				agregar(e4);
				FlagBoss2 = 0;
			}
			if (FlagBoss3 && v <= 10)
			{
				
				Enemigo* e5 = new Enemigo(172, 115,3,3);
				
				Enemigo* e6 = new Enemigo(167, 115, 3, 3);
				
				agregar(e5);
				agregar(e6);
				FlagBoss3 = 0;
			}
		}
	}
}

void ListaEnemigos::colisionBoss()
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getBioma() == 4)
		{
			
			bool b=Interaccion::colision(lista[i]);
			if (b == 1)
			{
				Vector2D vel = lista[i]->GetVel();
				lista[i]->setVelx(-vel.x);
			}
		}
	}
}