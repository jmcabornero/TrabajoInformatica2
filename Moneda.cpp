#include "Moneda.h"

Moneda::Moneda(int x, int y, int t)
{
	i = x;j = y;
	tipo = t; //tipo=1 si es verde  tipo=2 si es roja
}

void Moneda::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	if (tipo==1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Monedas/Verde.png").id);
	if (tipo==2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Monedas/Roja.png").id);
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

Vector2D Moneda::GetEsquina()
{
	Vector2D vec;
	vec.x = j;
	vec.y = i;
	return vec;
}