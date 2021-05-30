#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo(float x)
{
	z_ojo = x;
}

void Mundo::dibuja()
{
	gluLookAt(posicion_ojo.x, posicion_ojo.y, z_ojo,
		posicion_ojo.x, posicion_ojo.y, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA
	
	
	protagonista.Dibuja();
	caja2.Dibuja2();
	caja.Dibuja();
	
	
	listaobstaculos.Dibuja();
	disparos.dibuja();
}

void Mundo::mueve()
{
	protagonista.Mueve(0.15f);
	listaobstaculos.Colision(&protagonista);
	disparos.mueve(0.025f);
	CambioCamara();
}

void Mundo::inicializa()
{
	dibObstaculos();
	posicion_ojo.x = 10.25f;    
	posicion_ojo.y = 7.5f;             
	z_ojo = 50.0f;  //20.5             
	protagonista.setTam(1, 1);
}

void Mundo::setPos(float x, float y)
{
	posicion_ojo.x = x;
	posicion_ojo.y = y;
}

void Mundo::tecla(unsigned char key)
{
	switch (key)
	{
	/*case 'w':
		protagonista.setVely(1.0f);
		break;
	case 's':
		protagonista.setVely(-1.0f);
		break;
	case 'a':
		protagonista.setVelx(-1.0f);
		break;
	case 'd':
		protagonista.setVelx(1.0f);
		break;*/
	case ' ':
	{
		Vector2D h_pos = protagonista.GetPos();
		Disparo* d = new Disparo();
		d->setPos(h_pos.x, h_pos.y);
		d->setVel(5, 0);
		disparos.agregar(d);
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

void Mundo::dibObstaculos()
{
	string line;
	ifstream myfile; //myfile es el fichero (puntero)
	myfile.open("imagenes/estrellas_OBSTACULOS.csv");
	if (myfile.is_open())
	{
		float i = 0, j, num;
		while (getline(myfile, line)) // line es una str con la siguiente linea
		{
			std::string delimiter = ",";
			size_t pos = 0;
			std::string token;
			j = 0;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				token = line.substr(0, pos);
				num = stoi(token);
				glEnable(GL_TEXTURE_2D);
				if (num == 478)
				{
					listaobstaculos.Agregar(new Obstaculos(-i+29, j));
				}
				line.erase(0, pos + delimiter.length());
				j++;
			}
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

void Mundo::CambioCamara()
	{
	Vector2D prota = protagonista.GetPos();
	if (prota.x > (posicion_ojo.x + 10.25))
		posicion_ojo.x += 20.0f;
	if (prota.x < (posicion_ojo.x - 10.25))
		posicion_ojo.x -= 20.0f;
	if (prota.y > (posicion_ojo.y+ 7.5))
		posicion_ojo.y += 15.0f;
	if (prota.y < (posicion_ojo.y - 7.5))
		posicion_ojo.y -= 15.0f;
	}


Mundo::~Mundo()
{
	disparos.destruirContenido();
}

