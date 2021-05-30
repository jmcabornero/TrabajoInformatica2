#include "Enemigo.h"

Enemigo::~Enemigo(){}


Enemigo::Enemigo()
{
	setDir('d');
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	posicion.x = 5; posicion.y = 8; velocidad = 0; velocidad = 0;
}

void Enemigo::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
//gestion de direccion y animacion
	if (velocidad.x > 0.01)spriteR.draw();
	if (velocidad.x < -0.01)spriteL.draw();
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))sprite.draw();
	glPopMatrix();
	

}

void Enemigo::Mueve(float t)
{
	ObjetosMovimiento::mueve(t);
	sprite.loop();
	spriteR.loop();
	spriteL.loop();
}

void Enemigo::setTam(float anchura, float altura)
{
	sprite.setCenter(1, 0);
	sprite.setSize(anchura, altura);
	spriteR.setCenter(1, 0);
	spriteR.setSize(anchura, altura);
	spriteL.setCenter(1, 0);
	spriteL.setSize(anchura, altura);
}

void Enemigo::ModVida(int m)
{
	vida.ModVida(m);
	if (vida.getVida() <= 0)
	{
		Enemigo::~Enemigo();
	}

}