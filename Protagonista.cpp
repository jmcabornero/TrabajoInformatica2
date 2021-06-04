#include "Protagonista.h"
#include "ETSIDI.h"


Protagonista::Protagonista()
{
	setDir('d');
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	posicion.x = 5;posicion.y = 126;velocidad = 0;velocidad = 0;
}

void Protagonista::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.01);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
//gestion de direccion y animacion
	if (velocidad.x > 0.01)spriteR.draw();
	if (velocidad.x < -0.01)spriteL.draw();
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))sprite.draw();
	glPopMatrix();
}

void Protagonista::Mueve(float t)
{
	ObjetosMovimiento::mueve(t);
	sprite.loop();
	spriteR.loop();
	spriteL.loop();
}

void Protagonista::setTam(float anchura, float altura)
{
	sprite.setCenter(1, 0);
	sprite.setSize(anchura, altura);
	spriteR.setCenter(1, 0);
	spriteR.setSize(anchura, altura);
	spriteL.setCenter(1, 0);
	spriteL.setSize(anchura, altura);
}

