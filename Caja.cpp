#include "Caja.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "GLAUX.h" 

Caja::Caja()
{
	
}

void Caja::Dibuja()
{
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Mapa/Mapa.png").id);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);glVertex3d(0, 135, 0);
	glTexCoord2d(1, 0);glVertex3d(201, 135, 0);
	glTexCoord2d(1, 1);glVertex3d(201, 0, 0);
	glTexCoord2d(0, 1);glVertex3d(0, 0, 0);
	//glTexCoord2d(0, 1); glVertex2f(0, 0);
	//glTexCoord2d(1, 1); glVertex2f(41, 0);
	//glTexCoord2d(1, 0); glVertex2f(41, 30);
	//glTexCoord2d(0, 0); glVertex2f(0, 30);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}

void Caja::Dibuja2()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Skele_War.png").id);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 0);glVertex3d(0, 135, 0.1);
	glTexCoord2d(1, 0);glVertex3d(10, 135, 0.1);
	glTexCoord2d(1, 1);glVertex3d(10, 125, 0.1);
	glTexCoord2d(0, 1);glVertex3d(0, 125, 0.1);
	//glTexCoord2d(0, 1); glVertex2f(0, 0);
	//glTexCoord2d(1, 1); glVertex2f(41, 0);
	//glTexCoord2d(1, 0); glVertex2f(41, 30);
	//glTexCoord2d(0, 0); glVertex2f(0, 30);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

Caja:: ~Caja()
{

}
