#include "Enemigo.h"




Enemigo::~Enemigo(){}


Enemigo::Enemigo(float x, float y)
{
	setDir('d');
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	posicion.x = x; posicion.y = y; velocidad = 0; velocidad = 0;
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

void Enemigo::Perseguir(Protagonista p)
{
	Vector2D pos_p = p.GetPos();
	Vector2D pos_e = GetPos();
	Vector2D delta = pos_p - pos_e;
	float angulo = atan2(delta.y, delta.x);
	float distancia = delta.modulo();
	if (distancia <= 4)
	{
		setVel(0.5 * cos(angulo), 0.5 * sin(angulo));
	}
}