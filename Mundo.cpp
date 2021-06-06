#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>
#include <time.h>
#define MAX_LENMENSAJE 1000
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
	
	caja.Dibuja();
	caja.Dibuja2();
	
	enemigos.dibuja();

	listaobstaculos.Dibuja();

	disparos.dibuja();

	//hud.dibuja("hello");

	DibujaMensajes();
	
}

void Mundo::mueve()
{
	protagonista.Mueve(0.15f);
	listaobstaculos.Colision(&protagonista);
	disparos.mueve(0.025f);
	CambioCamara();
	for (int i = 0; i < enemigos.getNumero(); i++)
	{
		disparos.colision(enemigos[i]);
	}
	enemigos.dano();
	for (int i = 0; i < listaobstaculos.getNumero(); i++)
	{
		disparos.colision(listaobstaculos[i]);
	}
	disparos.Cooldawn();
	protagonista.FuncionTeletransporte();
}

void Mundo::inicializa()
{
	dibObstaculos();
	posicion_ojo.x = 10.25f;    
	posicion_ojo.y = 7.5f;    
	z_ojo = 20.5f; //20.5f   
	protagonista.setTam(1, 1);

	for (int i = 0; i < 8; i++)
	{
		Enemigo* aux = new Enemigo(i+2,7);
		enemigos.agregar(aux);
	}
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
	case ' ':
	{
		if (disparos.flag == 0)
		{
			Vector2D h_pos = protagonista.GetPos();
			Disparo* d = new Disparo();
			d->setPos(h_pos.x, h_pos.y);
			
			switch (protagonista.getDir()) {
			case 'd':
				d->setVel(10, 0);
				break;
			case 'a':
				d->setVel(-10, 0);
				break;
			case 'w':
				d->setVel(0, 10);
				break;
			case 's':
				d->setVel(0, -10);
				break;
			}
			disparos.agregar(d);
		};		
	}
	break;
	}
}

void Mundo::teclaEspecial(unsigned char key) //al pulsar la tecla
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		protagonista.setVelx(-1.0f);
		protagonista.setDir('a');
		break;
	case GLUT_KEY_RIGHT:
		protagonista.setVelx(1.0f);
		protagonista.setDir('d');
		break;
	case GLUT_KEY_DOWN:
		protagonista.setVely(-1.0f);
		protagonista.setDir('s');
		break;
	case GLUT_KEY_UP:
		protagonista.setVely(1.0f);
		protagonista.setDir('w');
		break;
	}
	//std::cout << protagonista.getDir() << std::endl;
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
	myfile.open("imagenes/Mapa/estrellas_OBSTACULOS.csv");
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
					listaobstaculos.Agregar(new Obstaculos(-i+134, j));
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

void Mundo::CambioCamara()//cambio HUD
	{
	Vector2D prota = protagonista.GetPos();
	if (prota.x > (posicion_ojo.x + 10.25)) {
		posicion_ojo.x += 20.0f;
		hud.setPos(hud.getPos().x + 20.0f, hud.getPos().y);
	}
	if (prota.x < (posicion_ojo.x - 10.25)) {
		posicion_ojo.x -= 20.0f;
		hud.setPos(hud.getPos().x - 20.0f, hud.getPos().y);
	}	
		if (prota.y > (posicion_ojo.y + 7.5)) {
			posicion_ojo.y += 15.0f;
			hud.setPos(hud.getPos().x, hud.getPos().y + 15.0f);
	}
		if (prota.y < (posicion_ojo.y - 7.5)) {
			posicion_ojo.y -= 15.0f;
			hud.setPos(hud.getPos().x, hud.getPos().y - 15.0f);
	}
	}

void Mundo::DibujaMensajes()
{
	Vector2D prota = protagonista.GetPos();
	string mensaje="";
	char* char_arr;
	if (protagonista.MensajeBuda(8, 11, 129))
	{
		mensaje1.setPos(posicion_ojo.x-5, posicion_ojo.y-6);
		string line;
		ifstream myfile("textos/TextoTutorial1.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				mensaje.append(line);
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		char_arr = &mensaje[0];
		mensaje1.dibuja(char_arr);
	}
}

Mundo::~Mundo()
{
	disparos.destruirContenido();
}


//float t1 = time();

