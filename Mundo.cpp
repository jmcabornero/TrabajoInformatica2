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
	protagonista.Dibuja(posicion_ojo.x, posicion_ojo.y);
	escenariotiles.mapa();
}

void Mundo::mueve()
{
	protagonista.Mueve(0.025f);
}

void Mundo::inicializa()
{
	posicion_ojo.x = 0;
	posicion_ojo.y = 0;
	z_ojo = 10;
	

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
		velocidad_ojo.x = -1.0f;
		break;
	case GLUT_KEY_RIGHT:
		velocidad_ojo.x = 1.0f;
		break;
	case GLUT_KEY_DOWN:
		velocidad_ojo.y = -1.0f;
		break;
	case GLUT_KEY_UP:
		velocidad_ojo.y = 1.0f;
		break;
	}
}

void Mundo::teclaEspecialUp(unsigned char key)  //al dejar de pulsar la tecla
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		velocidad_ojo.x = 0;
		break;
	case GLUT_KEY_RIGHT:
		velocidad_ojo.x = 0;
		break;
	case GLUT_KEY_DOWN:
		velocidad_ojo.y = 0;
		break;
	case GLUT_KEY_UP:
		velocidad_ojo.y = 0;
		break;
	}
}


void Mundo::MueveCamara(float t)
{
	posicion_ojo = posicion_ojo + velocidad_ojo * t;
}

Mundo::~Mundo()
{
	
}

