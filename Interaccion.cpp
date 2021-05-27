#include "Interaccion.h"


bool Interaccion::colision(Protagonista p, Obstaculos &o)
{
	Vector2D esquina = o.GetEsquina();
	Vector2D esquinasuperior = esquina + (1, 1);
	Vector2D prota = p.GetPos();
	if (((esquina.x < prota.x) && (prota.x < esquinasuperior.x)) || ((esquina.y < prota.y) && (prota.y < esquinasuperior.y)))
		return true;
	else return false;
}