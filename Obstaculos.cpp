#include "Obstaculos.h"

Obstaculos::Obstaculos(int x, int y)
{
	i = x;j = y;
}

void Obstaculos::Dibuja()
{
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HierbaAux.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(j, i); //abajo izq
	glTexCoord2d(1, 1); glVertex2f(j + 1, i);	//abajo drcha
	glTexCoord2d(1, 0); glVertex2f(j + 1, i + 1);	//arriba drcha
	glTexCoord2d(0, 0); glVertex2f(j, i + 1);	//arriba izq
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

Vector2D Obstaculos::GetEsquina()
{
	Vector2D vec;
	vec.x = j;
	vec.y = i;
	return vec;
}