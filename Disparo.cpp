#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
	sprite.setCenter(0.5, 0.5);
	sprite.setSize(1, 1);
	setPos(5, 5);
	setVel(5, 0);
	setRadio(0.25);
}

Disparo::~Disparo() {

}

void Disparo::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(radio, 20, 20);
	sprite.draw();
	glPopMatrix();
}

void Disparo::mueve(float t) {
	ObjetosMovimiento::mueve(t);
	sprite.loop();
}