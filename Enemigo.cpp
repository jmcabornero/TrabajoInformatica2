#include "Enemigo.h"



Enemigo::~Enemigo(){}


Enemigo::Enemigo(float x, float y, int b, int t)
{
	setDir('d');
	sprite.setCenter(1, 0);
	sprite.setSize(1, 1);
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	posicion.x = x; posicion.y = y; velocidad = 0; velocidad = 0;
	setFlag(0);
	setTipo(t);
	setBioma(b);
	vel = 1;
	switch (getBioma())
	{
	case 1:
		switch (getTipo())
		{
		case 1:
			break;
		case 2:
			setDef(0.5);
			modVel(2);
			break;
		case 3:
			setDef(0.25);
			setAttack(0.75);
			setCoolDown(4.0);
			break;
		}
		break;
	case 2:
		switch (getTipo())
		{
		case 1:
			setDef(1.5);
			setAttack(1.5);
			break;
		case 2:
			setDef(0.75);
			modVel(1.25);
			break;
		case 3:
			setDef(0.5);
			setAttack(1);
			modVel(1.25);
			setCoolDown(4.0);
			break;
		}
		break;
	case 3:
		switch (getTipo())
		{
		case 1:
			setDef(2.5);
			setAttack(2.5);
			break;
		case 2:
			setDef(1);
			modVel(2);
			break;
		case 3:
			setDef(0.75);
			setAttack(1.5);
			setCoolDown(4.0);
			break;
		}
		break;
	}





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
		setVel(vel * cos(angulo), vel * sin(angulo));
		
	else
		setVel(0, 0);
}


