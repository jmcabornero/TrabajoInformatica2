#include "Enemigo.h"
Enemigo::~Enemigo(){}


Enemigo::Enemigo(float x, float y, int b, int t)
{
	setDir('d');
	spriteR.setCenter(1, 0);
	spriteR.setSize(2, 2);
	spriteL.setCenter(1, 0);
	spriteL.setSize(2, 2);
	spriteUp.setCenter(1, 0);
	spriteUp.setSize(2, 2);
	spriteDown.setCenter(1, 0);
	spriteDown.setSize(2, 2);
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
			setCoolDownPref(4.0);
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
	//gestion de direccion y animacion
	if (velocidad.x > 0.001) {
		setDir('d');
		spriteR.draw();
		//cout << "sprite D" << endl;
	}
	if (velocidad.x < -0.001) {
		setDir('a');
		spriteL.draw();
		//cout << "sprite A" << endl;
	}
	if ((velocidad.y > 0.001) && (velocidad.x < 0.001) && (velocidad.x > -0.001)) {
		setDir('w');
		spriteUp.draw();
		//cout << "sprite W" << endl;
	}
	if ((velocidad.y < -0.001) && (velocidad.x < 0.001) && (velocidad.x > -0.001)) {
		setDir('s');
		spriteDown.draw();
		//cout << "sprite S" << endl;
	}

	if ((velocidad.x < 0.001) && (velocidad.x > -0.001) && (velocidad.y < 0.001) && (velocidad.y > -0.001)) {
		switch (direccion) {
		case 'a':
			spriteL.setState(1, false);
			spriteL.draw();
			break;
		case 'd':
			spriteR.setState(1, false);
			spriteR.draw();
			break;
		case 'w':
			spriteUp.setState(1, false);
			spriteUp.draw();
			break;
		case 's':
			spriteDown.setState(1, false);
			spriteDown.draw();
			break;
		}
	}
	glPopMatrix();
	//std::cout << "velocidad: ( " << velocidad.x << " , " << velocidad.y << " )" << std::endl;
	//std::cout << "direccion: " << direccion << std::endl;
}

void Enemigo::Mueve(float t)
{
	ObjetosMovimiento::mueve(t);
	spriteR.loop();
	spriteL.loop();
	spriteUp.loop();
	spriteDown.loop();
}

void Enemigo::setTam(float anchura, float altura)
{
	spriteR.setCenter(1, 0);
	spriteR.setSize(anchura, altura);
	spriteL.setCenter(1, 0);
	spriteL.setSize(anchura, altura);
	spriteUp.setCenter(1, 0);
	spriteUp.setSize(anchura, altura);
	spriteDown.setCenter(1, 0);
	spriteDown.setSize(anchura, altura);
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


