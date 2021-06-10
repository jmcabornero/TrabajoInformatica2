#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>
#include <sstream>
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
	listacofres.Dibuja();
	listaobstaculos.Dibuja();
	listapinchos.Dibuja();
	monedas.Dibuja();

	disparos.dibuja();

	DibujaMensajes();

	protagonista.dibujaStats(posicion_ojo.x - 3, posicion_ojo.y + 6.5);
	
}

void Mundo::mueve()
{
	protagonista.Mueve(0.15f);
	listaobstaculos.Colision(&protagonista,1);
	listapinchos.Colision(&protagonista, 2);
	monedas.Colision(&protagonista);
	listacofres.Transformacion(&protagonista);
	disparos.mueve(0.025f);
	CambioCamara();
	for (int i = 0; i < enemigos.getNumero(); i++)
	{
		disparos.colision(enemigos[i]);
	}
	enemigos.dano(&monedas);
	enemigos.Perseguir(protagonista);
	enemigos.mueve(0.15f);
	for (int i = 0; i < listaobstaculos.getNumero(); i++)
	{
		disparos.colision(listaobstaculos[i]);
	}
	disparos.Cooldown(protagonista);
	protagonista.FuncionTeletransporte();
}

/*std::string getStats(Protagonista &p) {
	using namespace std;
	string hp = convert(p.getVida());
	string def = convert(p.getDef());
	string att = convert(p.getAttack());
	string v = convert(p.getVel());
	string cdown = convert(p.getCoolDown());
	string as = convert(p.getAttackspeed());
	string money = convert(p.getDinero());

	string vida = "vida: ";
	string defensa = "defensa: ";
	string ataque = "ataque: ";
	string velocidad = "velocidad: ";
	string cooldown = "cooldown: ";
	string vel_ataque = "velocidad de ataque: ";
	string dinero = "dinero: ";
	string aux = "/100";

	string str_stats = vida + hp + aux + '\n' + defensa + def + '\n' + ataque + att + '\n' + velocidad + v + '\n' + cooldown + cdown + '\n' + vel_ataque + as + '\n' + dinero + money + '\n';
	return str_stats;
}*/

void Mundo::inicializa()
{
	dibObstaculos(1);
	dibObstaculos(2);
	listacofres.CrearCofres();
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
		disparos.Disparar(protagonista);
	}
	break;
	}
}

void Mundo::teclaEspecial(unsigned char key) //al pulsar la tecla
{
	float vel = protagonista.GetVelAbs();
	switch (key)
	{
	case GLUT_KEY_LEFT:
		protagonista.setVelx(-vel);
		protagonista.setDir('a');
		break;
	case GLUT_KEY_RIGHT:
		protagonista.setVelx(vel);
		protagonista.setDir('d');
		break;
	case GLUT_KEY_DOWN:
		protagonista.setVely(-vel);
		protagonista.setDir('s');
		break;
	case GLUT_KEY_UP:
		protagonista.setVely(vel);
		protagonista.setDir('w');
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

void Mundo::dibObstaculos(int n)
{
	string line;
	ifstream myfile; //myfile es el fichero (puntero)
	if (n==1)
		myfile.open("imagenes/Mapa/estrellas_OBSTACULOS.csv");
	if (n==2)
		myfile.open("imagenes/Mapa/estrellas_PINCHOS.csv");
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
				if (num == 284)
				{
					listapinchos.Agregar(new Obstaculos(-i + 134, j));
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
	}
	if (prota.x < (posicion_ojo.x - 10.25)) {
		posicion_ojo.x -= 20.0f;	
	}	
		if (prota.y > (posicion_ojo.y + 7.5)) {
			posicion_ojo.y += 15.0f;	
		}
		if (prota.y < (posicion_ojo.y - 7.5)) {
			posicion_ojo.y -= 15.0f;	
		}
	}

void Mundo::DibujaMensajes()
{
	Vector2D prota = protagonista.GetPos();
	string mensaje="";
	char char_arr[MAX_LENMENSAJE];
	char* char_arr2;
	char_arr[0] = '\0';
	if (protagonista.MensajeBuda(8, 11, 129))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y-4);
		string line;
		ifstream myfile("textos/TextoTutorial1.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(2, 5, 114))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoTutorial2.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(53, 56, 116))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoTutorial3.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(103, 106, 67))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoTienda1.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(112, 115, 67))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoTienda2.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(49, 52, 70))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoDesierto.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(128, 131, 25))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoNieve.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(168, 171, 94))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoBudaFinal.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
	if (protagonista.MensajeBuda(168, 171, 100))
	{
		mensaje1.setPos(posicion_ojo.x, posicion_ojo.y - 4);
		string line;
		ifstream myfile("textos/TextoBossFinal.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				char_arr2 = &line[0];
				strcat(char_arr, char_arr2);
				strcat(char_arr, "\n");
			}
			myfile.close();
		}
		else cout << "Unable to open file";
		mensaje1.dibuja(char_arr);
	}
}

Mundo::~Mundo()
{
	disparos.destruirContenido();
}


//float t1 = time();

