#include "Interaccion.h"


bool Interaccion::colision(Protagonista p, Obstaculos &o)
{
	Vector2D esquina = o.GetEsquina();
	Vector2D prota = p.GetPos();
	if ((((esquina.x+0.3) <= prota.x) && (prota.x <= (esquina.x+1.8f))) && (((esquina.y-0.9f) <= prota.y) && (prota.y <= (esquina.y+0.9f))))
	{
		return true;
	}
	else
	{	
		return false;
	}		
}

bool Interaccion::colision(Disparo &d, Enemigo &e)
{
	Vector2D aux = (d.GetPos() - e.GetPos());
	float distancia = aux.modulo();

	if (distancia <= 0.6)
	{
		return true;
	}
	else
		return false;
}


bool Interaccion::colision(Disparo& d, Obstaculos& o)
{
	Vector2D esquina = o.GetEsquina();
	Vector2D disp = d.GetPos();
	if ((((esquina.x + 0.3) <= disp.x) && (disp.x <= (esquina.x + 1.8f))) && (((esquina.y - 0.9f) <= disp.y) && (disp.y <= (esquina.y + 0.9f))))
	{
		cout << "colision";
		return true;
	}
	else
	{
		return false;
	}
}