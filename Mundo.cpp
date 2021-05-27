#include "Mundo.h"
#include "freeglut.h"
#include <math.h>


/*void Mundo::rotarOjo()
{
	float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
	float ang = atan2(z_ojo, x_ojo);
	ang += 0.05f;
	x_ojo = dist * cos(ang);
	z_ojo = dist * sin(ang);
}*/

void Mundo::dibuja()
{
	gluLookAt(posicion_ojo.x, posicion_ojo.y, z_ojo,
		posicion_ojo.x, posicion_ojo.y, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	protagonista.Dibuja();
	caja.Dibuja();
	//escenariotiles.mapa();
}

void Mundo::mueve()
{
	protagonista.Mueve(0.15f);
}

void Mundo::inicializa()
{
	posicion_ojo.x = 10.0f;
	posicion_ojo.y = 7.5f;
	z_ojo = 20.5f;
	

	protagonista.setTam(1, 1);
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	case '1':
		
		break;
	case '2':
		
		break;
	case '3':
		
		break;
	case '4':
		
		break;
	case ' ':
	{
		
		break;
	}
	}
}

void Mundo::teclaEspecial(unsigned char key) //al pulsar la tecla
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		protagonista.setVelx(-1.0f);
		break;
	case GLUT_KEY_RIGHT:
		protagonista.setVelx(1.0f);
		break;
	case GLUT_KEY_DOWN:
		protagonista.setVely(-1.0f);
		break;
	case GLUT_KEY_UP:
		protagonista.setVely(1.0f);
		break;
	}
}

void Mundo::teclaEspecialUp(unsigned char key)  //al dejar de pulsar la tecla
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		protagonista.setVelx(0);
		break;
	case GLUT_KEY_RIGHT:
		protagonista.setVelx(0);
		break;
	case GLUT_KEY_DOWN:
		protagonista.setVely(0);
		break;
	case GLUT_KEY_UP:
		protagonista.setVely(0);
		break;
	}
}

Mundo::~Mundo()
{
	
}

