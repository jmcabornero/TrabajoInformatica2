#include "Caja.h"
#include "freeglut.h"
#include "ETSIDI.h"
Caja::Caja()
{
	
}

void Caja::Dibuja()
{
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/MapaPrueba.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0, 0);
	glTexCoord2d(1, 1); glVertex2f(40, 0);
	glTexCoord2d(1, 0); glVertex2f(40, 30);
	glTexCoord2d(0, 0); glVertex2f(0, 30);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

Caja:: ~Caja()
{

}
