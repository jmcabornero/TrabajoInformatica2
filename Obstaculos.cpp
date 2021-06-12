#include "Obstaculos.h"

Obstaculos::Obstaculos(int x, int y, int tip)
{
	i = x;j = y,tipo=tip;
}

void Obstaculos::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	if(tipo==2)
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Obstaculos/Snorlax.png").id);
	if(tipo==3)
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Obstaculos/Matlab_Logo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	if (tipo == 2 || tipo == 3)
	{
		glTexCoord2d(0, 1); glVertex3d(j, i, 0.3); //abajo izq
		glTexCoord2d(1, 1); glVertex3d(j + 1, i, 0.03);	//abajo drcha
		glTexCoord2d(1, 0); glVertex3d(j + 1, i + 1, 0.03);	//arriba drcha
		glTexCoord2d(0, 0); glVertex3d(j, i + 1, 0.03);	//arriba izq
	}
	if (tipo == 1)
	{
		glTexCoord2d(0, 1); glVertex2f(j, i); //abajo izq
		glTexCoord2d(1, 1); glVertex2f(j + 1, i);	//abajo drcha
		glTexCoord2d(1, 0); glVertex2f(j + 1, i + 1);	//arriba drcha
		glTexCoord2d(0, 0); glVertex2f(j, i + 1);	//arriba izq
	}
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
