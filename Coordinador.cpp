#include "Coordinador.h"

Coordinador::Coordinador()
{
	estado = INICIO;
};

Coordinador::~Coordinador()
{

};

void Coordinador::Inicializa()
{

};

void Coordinador::Dibuja()
{
	if (estado == INICIO) {

		gluLookAt(0.0, 7.5, 30.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/casa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}

	else if (estado == JUEGO) {
		mundo.dibuja();
	}

	else if (estado == PAUSA) {
		//mundo.dibuja();

		gluLookAt(0.0, 7.5, 30.0,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pausa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(1, 1); glVertex3f(-15, -4, -0.1);
		glTexCoord2d(1, 0); glVertex3f(-15, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(15, 20, -0.1);
		glTexCoord2d(0, 1); glVertex3f(15, -4, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
};

void Coordinador::Mueve() {
	if (estado == JUEGO) {
		mundo.mueve();

		/*INTRODUCIR LA CONDICION PARA CAMBIAR DE ESTADO*/
		//Acordarse de resetear el valor i al cambiar a estados con animacion
	}
}
void Coordinador::Tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key >= 0 && key <= 256) {
			mundo.inicializa();
			estado = JUEGO;
		}
	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
		switch (key) {
		case 27:
			estado = PAUSA;
			break;
		}
	}

	else if (estado == PAUSA) {
		switch (key) {
		case 27:
			exit(0);
			break;
		case 'C':
		case 'c':
			estado = JUEGO;
			break;
		}
	}
};

void Coordinador::TeclaEspecial(int key) {
	if (estado == JUEGO) {
		mundo.teclaEspecial(key);
	}
};

void Coordinador::TeclaEspecialUp(int key) {
	if (estado == JUEGO) {
		mundo.teclaEspecialUp(key);

	}
}