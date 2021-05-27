#include "Caja.h"
#include "freeglut.h"
#include "ETSIDI.h"
Caja::Caja()
{
	suelo.setColor(0, 100, 0);
	suelo.setPos(-10.0f, 0, 10.0f, 0);
	techo.setColor(0, 100, 0);
	techo.setPos(-10.0f, 15.0f, 10.0f, 15.0f);

	pared_dcha.setColor(0, 150, 0);
	pared_dcha.setPos(-10.0f, 0, -10.0f, 15.0f);
	pared_izq.setColor(0, 150, 0);
	pared_izq.setPos(10.0f, 0, 10.0f, 15.0f);
}

void Caja::Dibuja()
{
	//suelo.Dibuja();
	//techo.Dibuja();
	//pared_izq.Dibuja();
	//pared_dcha.Dibuja();
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
