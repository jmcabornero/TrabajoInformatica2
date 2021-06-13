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
	mensajestienda.DibujaTiendaMaster(&protagonista, posicion_ojo.x, posicion_ojo.y);
	
	enemigos.dibuja();
	listacofres.Dibuja(posicion_ojo.x, posicion_ojo.y);
	listaobstaculos.Dibuja();
	listapinchos.Dibuja();
	monedas.Dibuja();

	

	disparos.dibuja();

	DibujaMensajes();

	//protagonista.dibujaStats(posicion_ojo.x - 3, posicion_ojo.y + 6.5);
	hud.dibujaHUD(&protagonista);
	hud_stats.dibujaStats(&protagonista, posicion_ojo.x - 7.5, posicion_ojo.y + 6.3);
	hud_cons.dibujaCons(&protagonista, posicion_ojo.x + 9, posicion_ojo.y + 6.3);

	enemigos.Disparar(&disparos);
	enemigos.CoolDown();
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
	disparos.colision(&protagonista);
	enemigos.dano(&monedas);
	enemigos.Perseguir(protagonista);
	enemigos.mueve(0.1f);
	for (int i = 0; i < listaobstaculos.getNumero(); i++)
	{
		disparos.colision(listaobstaculos[i]);
	}
	disparos.Cooldown(protagonista);
	protagonista.FuncionTeletransporte();
	hud.setPos(protagonista.GetPosx(), protagonista.getPosy() + 1.5f);
	enemigos.kamikaze(protagonista);

	enemigos.distProta(protagonista);
}

void Mundo::inicializa()
{
	protagonista.setPos(7, 125); //nuevo
	enemigos.destruirContenido(); //nuevo, seguir con esto
	monedas.destruirContenido(); //subir esto
	listaobstaculos.destruirContenido();
	listapinchos.destruirContenido();
	listacofres.destruirContenido();

	dibObstaculos(1);
	dibObstaculos(2);
	dibEnemigos();
	listacofres.CrearCofres();
	posicion_ojo.x = 10.25f;
	posicion_ojo.y = 7.5f;
	z_ojo = 20.5f; //20.5f   
	protagonista.setTam(2, 2);
	protagonista.setVida(100);
	protagonista.setVel(0, 0);
	protagonista.SetVelAbs(1);
	protagonista.setPociones(0);
	protagonista.setDinero(0);
	protagonista.setAttackspeed(1);
	protagonista.setAttack(1);
	protagonista.setDef(1);

	for (int i = 0; i < 2; i++)
	{
		Enemigo* aux = new Enemigo(i+2,123,1,3);
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
	case 'c':
	case 'C':
	{
		int npociones = protagonista.getPociones();
		int vida = protagonista.getVida();
		if ((npociones > 0)&&(vida<100))
		{
			protagonista.setVida(protagonista.getVida() + 20);
			protagonista.setPociones(npociones - 1);
		}
	}
	break;
	}
	Vector2D prota = protagonista.GetPos();
	int dinero = protagonista.getDinero();
	float vel = protagonista.GetVelAbs();
	if ((prota.x >= 105) && (prota.x <= 109) && (prota.y >= 80) && (prota.y <= 84))
	{
		switch (key)
		{
		case '1':
		{
			if (dinero > 20)
			{
				protagonista.setPociones(protagonista.getPociones() + 1);
				protagonista.setDinero(protagonista.getDinero() - 10);	
			}
			break;
		}
		}
		if ((prota.x >= 107) && (prota.x <= 111) && (prota.y >= 96) && (prota.y <= 100))
		{
			switch (key)
			{
			case '1':
			{
				if (dinero > 20)
				{
					protagonista.setDef(protagonista.getDef() + 1);
					protagonista.setDinero(protagonista.getDinero() - 20);
				}
				break;
			}
			case '2':
			{
				if (dinero > 20)
				{
					protagonista.setAttack(protagonista.getAttack() + 1);
					protagonista.setDinero(protagonista.getDinero() - 20);
				}
				break;
			}
			case '3':
			{
				if ((dinero > 20)&&(vel<2))
				{
					protagonista.SetVelAbs(protagonista.GetVelAbs() + 0.1);
					protagonista.setDinero(protagonista.getDinero() - 20);
				}
				break;
			}
			case '4':
			{
				if (dinero > 20)
				{
					protagonista.setAttackspeed(protagonista.getAttackspeed() + 1);
					protagonista.setDinero(protagonista.getDinero() - 20);
				}
				break;
			}
			}
		}

	}
}

void Mundo::teclaEspecial(unsigned char key) //al pulsar la tecla
{
	float vel = protagonista.GetVelAbs();
	switch (key)
	{
	case GLUT_KEY_LEFT:
		protagonista.setVelx(-vel);
		break;
	case GLUT_KEY_RIGHT:
		protagonista.setVelx(vel);
		break;
	case GLUT_KEY_DOWN:
		protagonista.setVely(-vel);
		break;
	case GLUT_KEY_UP:
		protagonista.setVely(vel);
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
					listaobstaculos.Agregar(new Obstaculos(-i+134, j,1));
				if (num == 284)
					listapinchos.Agregar(new Obstaculos(-i + 134, j,1));
				if (num == 50)
					listaobstaculos.Agregar(new Obstaculos(-i + 134, j,2));
				if (num == 269)
					listaobstaculos.Agregar(new Obstaculos(-i + 134, j,3));
				line.erase(0, pos + delimiter.length());
				j++;
			}
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

void Mundo::dibEnemigos()
{
	string line;
	ifstream myfile; //myfile es el fichero (puntero)
		myfile.open("imagenes/Mapa/estrellas_ENEMIGOS.csv");
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
				if (num == 89)
					enemigos.agregar(new Enemigo(j, -i + 134,1,1));
				if (num == 90)
					enemigos.agregar(new Enemigo(j, -i + 134,1,2));
				if (num == 91)
					enemigos.agregar(new Enemigo(j, -i + 134,1,3));
				if (num == 92)
					enemigos.agregar(new Enemigo(j, -i + 134,2,1));
				if (num == 93)
					enemigos.agregar(new Enemigo(j, -i + 134,2,2));
				if (num == 94)
					enemigos.agregar(new Enemigo(j, -i + 134,2,3));
				if (num == 95)
					enemigos.agregar(new Enemigo(j, -i + 134,3,1));
				if (num == 104)
					enemigos.agregar(new Enemigo(j, -i + 134,3,2));
				if (num == 105)
					enemigos.agregar(new Enemigo(j, -i + 134,3,3));
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


float Mundo::GetVidas()
{
	return protagonista.getVida();

}

Mundo::~Mundo()
{
	disparos.destruirContenido();
}


//float t1 = time();

