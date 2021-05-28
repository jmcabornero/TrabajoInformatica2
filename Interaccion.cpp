#include "Interaccion.h"


bool Interaccion::colision(Protagonista p, Obstaculos &o)
{
	Vector2D esquina = o.GetEsquina();
	Vector2D prota = p.GetPos();
	if (((esquina.x <= prota.x) && (prota.x <= (esquina.x+1))) && ((esquina.y <= prota.y) && (prota.y <= (esquina.y+1))))
	{
		return true;
	}
	else
	{	
		return false;
	}		
}