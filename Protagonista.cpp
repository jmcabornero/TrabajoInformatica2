#include "Protagonista.h"
#include "ETSIDI.h"
#include <iostream>
#include <sstream>


Protagonista::Protagonista()
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

	posicion.x = 111;posicion.y = 80;velocidad.x = 0;velocidad.y = 0, velabs=1;
	setVida(100);
	//std::cout << "Vida: " << vida.getVida() << std::endl;
	setFlag(0);
	setTdis(2);
}

void Protagonista::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.01);
	glColor3f(1.0f, 0.0f, 0.0f);
//gestion de direccion y animacion
	if (velocidad.x > 0.01) {
		setDir('d');
		spriteR.draw();
	}
	if (velocidad.x < -0.01) {
		setDir('a');
		spriteL.draw();
	}
	if ((velocidad.y > 0.01) && (velocidad.x < 0.01) && (velocidad.x > -0.01)) {
		setDir('w');
		spriteUp.draw();
	}
	if ((velocidad.y < -0.01) && (velocidad.x < 0.01) && (velocidad.x > -0.01)) {
		setDir('s');
		spriteDown.draw();
	}

	if ((velocidad.x < 0.01) && (velocidad.x > -0.01)&& (velocidad.y < 0.01) && (velocidad.y > -0.01)) {
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




void Protagonista::Mueve(float t)
{
	ObjetosMovimiento::mueve(t);
	spriteR.loop();
	spriteL.loop();
	spriteUp.loop();
	spriteDown.loop();
}

void Protagonista::setTam(float anchura, float altura)
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

void Protagonista::FuncionTeletransporte()
{
	Teletransporte(44, 109, 110, 66); //pozo
	Teletransporte(115, 54, 104, 51); //cueva de tierra a montaña
	Teletransporte(104, 50, 115, 53); //cueva de montaña a tierra
	Teletransporte(110, 71, 109, 76); //entrar tienda
	for (int i = 108;i <= 111;i++)Teletransporte(i, 75, 110, 70); //salir tienda
	for (int i = 88;i <= 89;i++)Teletransporte(114, i, 112, 93); //subir tienda
	for (int i = 92;i <= 93;i++)Teletransporte(114, i, 117, 87);; //bajar tienda
}

void Protagonista::Teletransporte(float inicio_x, float inicio_y, float final_x, float final_y)
{
	if ((((inicio_x + 0.3) <= posicion.x) && (posicion.x <= (inicio_x + 1.8f))) && (((inicio_y - 0.9f) <= posicion.y) && (posicion.y <= (inicio_y + 0.9f))))
	{
		setPos(final_x+1, final_y);
	}
}

bool Protagonista::MensajeBuda(float inicio_x, float final_x, float inicio_y)
{
	if ((((inicio_x + 0.3) <= posicion.x) && (posicion.x <= (final_x + 1.8f))) && (((inicio_y - 0.9f) <= posicion.y) && (posicion.y <= (inicio_y + 0.9f))))
	{
		return true;
	}
	else return false;
}

float Protagonista::GetVelAbs()
{
	return velabs;
}

void Protagonista::SetVelAbs(float vel)
{
	velabs = vel;
}

