#include "Protagonista.h"
#include "ETSIDI.h"


Protagonista::Protagonista()
{
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	posicion.x = 5;posicion.y = 5;velocidad = 0;velocidad = 0;
}

void Protagonista::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
//gestion de direccion y animacion
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();
}

void Protagonista::Mueve(float t)
{
	posicion = posicion + velocidad * t;
	sprite.loop();
}

void Protagonista::setTam(float anchura, float altura)
{
	sprite.setCenter(1, 0);
	sprite.setSize(anchura, altura);
}

void Protagonista::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
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