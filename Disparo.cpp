#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
	disparo_dcha.setCenter(0.5, 0.5);
	disparo_dcha.setSize(1, 1);
	disparo_izda.setCenter(0.5, 0.5);
	disparo_izda.setSize(1, 1);
	disparo_up.setCenter(0.5, 0.5);
	disparo_up.setSize(1, 1);
	disparo_down.setCenter(0.5, 0.5);
	disparo_down.setSize(1, 1);
	setPos(5, 5);
	setVel(5, 0);
	setRadio(0.25);
}

Disparo::~Disparo() {

}

void Disparo::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x-0.25, posicion.y-0.25, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(radio, 20, 20);
	if (velocidad.x > 0.01)disparo_dcha.draw();
	if (velocidad.x < -0.01)disparo_izda.draw();
	if (velocidad.y > 0.01)disparo_up.draw();
	if (velocidad.y < -0.01)disparo_down.draw();
	glPopMatrix();
	ident = 1;
}

void Disparo::mueve(float t) {
	ObjetosMovimiento::mueve(t);
	disparo_dcha.loop();
	disparo_izda.loop();
	disparo_up.loop();
	disparo_down.loop();
}


void Disparo::modIdent(int i)
{
	if (i > 3 || i < 0)
		ident = 1;
	else
		ident = i;
}