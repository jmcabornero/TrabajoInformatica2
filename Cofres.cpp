#include "Cofres.h"

Cofres::Cofres(float x, float y, int t)
{
	i = x; j = y; tipo = t;
}

void Cofres::Dibuja()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	if (tipo==1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cofres/Cerrado.png").id);
	if (tipo==2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Cofres/Abierto.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 0);glVertex3d(i, j, 0.03);
	glTexCoord2d(1, 0);glVertex3d(i + 1, j, 0.03);
	glTexCoord2d(1, 1);glVertex3d(i + 1, j + 1, 0.03);
	glTexCoord2d(0, 1);glVertex3d(i, j + 1, 0.03);
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

void Cofres::SetTipo(int a)
{
	a = tipo;
}

int Cofres::GetTipo()
{
	return tipo;
}


