#include "Cofres.h"

Cofres::Cofres(int x, int y, int t)
{
	i = x;j = y;
	t = tipo;
}

void Cofres::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	if (tipo==1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cofres/Cerrrado.png").id);
	if (tipo==2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cofres/Abierto.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(i, j); //abajo izq
	glTexCoord2d(1, 1); glVertex2f(i + 1, j);	//abajo drcha
	glTexCoord2d(1, 0); glVertex2f(i + 1, j + 1);	//arriba drcha
	glTexCoord2d(0, 0); glVertex2f(i, j + 1);	//arriba izq
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

Vector2D Cofres::GetEsquina()
{
	Vector2D vec;
	vec.x = i;
	vec.y = j;
	return vec;
}

