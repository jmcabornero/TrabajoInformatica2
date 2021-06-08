#include "Moneda.h"

Moneda::Moneda(int x, int y, int t)
{
	i = x;j = y;
	tipo = t; //tipo=1 si es verde  tipo=2 si es roja
}

void Moneda::Dibuja()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	if (tipo == 1)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Monedas/Verde.png").id);
	if (tipo == 2)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Monedas/Roja.png").id);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);glVertex3d(i, j, 0.03);
	glTexCoord2d(1, 0);glVertex3d(i+0.5, j, 0.03);
	glTexCoord2d(1, 1);glVertex3d(i+0.5, j+0.5, 0.03);
	glTexCoord2d(0, 1);glVertex3d(i, j + 0.5, 0.03);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

Vector2D Moneda::GetEsquina()
{
	Vector2D vec;
	vec.x = i;
	vec.y = j;
	return vec;
}