#include "Protagonista.h"
#include "ETSIDI.h"


Protagonista::Protagonista()
{
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	posicion.x = 5;posicion.y = 5;velocidad = 0;velocidad = 0;
}

void Protagonista::Dibuja()
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

void Protagonista::Mueve(float t)
{
	posicion = posicion + velocidad * t;
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

void Protagonista::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

void Protagonista::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void Protagonista::setVelx(float vx)
{
	velocidad.x = vx;
}

void Protagonista::setVely(float vy)
{
	velocidad.y = vy;
}

Vector2D Protagonista::GetPos()
{
	Vector2D vec;
	vec.x = posicion.x;
	vec.y = posicion.y;
	return vec;
}

Vector2D Protagonista::GetVel()
{
	Vector2D vec;
	vec.x = velocidad.x;
	vec.y = velocidad.y;
	return vec;
}