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