#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo(float x)
{
	z_ojo = x;
}
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
	
	listaobstaculos.Dibuja();
}

void Mundo::mueve()
{
	protagonista.Mueve(0.15f);
	listaobstaculos.Colision(&protagonista);
}

void Mundo::inicializa()
{
	dibObstaculos();
	posicion_ojo.x = 10.0f;
	posicion_ojo.y = 7.5f;
	z_ojo = 20.5f;
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

void Mundo::dibObstaculos()
{
	string line;
	ifstream myfile; //myfile es el fichero (puntero)
	myfile.open("imagenes/estrellas.csv");
	if (myfile.is_open())
	{
		int i = 0, j, num;
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
					//glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/HierbaAux.png").id);
					listaobstaculos.Agregar(new Obstaculos(i, j));
					/*glDisable(GL_LIGHTING);
					glBegin(GL_POLYGON);
					glColor3f(1, 1, 1);
					glTexCoord2d(0, 1); glVertex2f(j, i); //abajo izq
					glTexCoord2d(1, 1); glVertex2f(j + 1, i);	//abajo drcha
					glTexCoord2d(1, 0); glVertex2f(j + 1, i + 1);	//arriba drcha
					glTexCoord2d(0, 0); glVertex2f(j, i + 1);	//arriba izq
					glEnd();
					glEnable(GL_LIGHTING);
					glDisable(GL_TEXTURE_2D);*/
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

Mundo::~Mundo()
{
	
}

