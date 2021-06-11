#include "HUD.h"
#include "freeglut.h"
#include <string.h>
#define MAX_LENMENSAJE 1000
#define capa1 0.03f
#define capa2 0.04f
#define capa3 0.05f

HUD::HUD() {
	setAlto(4);
	setAncho(18.5);
	setPos(3.5, 13.5);
}

HUD::~HUD() {

}

void displayText(float x, float y, float z, int r, int g, int b, const char* string) {
	int j = strlen(string);

	glColor3f(r, g, b);
	glRasterPos3f(x, y, z);
	for (int i = 0; i < j; i++) {
		if (string[i] == '\n')
		{
			y=y-0.6;
			glRasterPos3f(x, y, z);
			continue;
		}
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void HUD::dibuja(char* mensaje) {
	float marco = 0.2;
	float h = getAlto();
	float a = getAncho();
	Vector2D p = getPos();
	glBegin(GL_POLYGON);
	glColor3f(255, 255, 255);
	glVertex3d(marco + p.x + a / 2, marco + p.y + h / 2, capa1);
	glVertex3d(marco + p.x + a / 2, -1*marco + p.y - h / 2, capa1);
	glVertex3d(-1*marco + p.x - a / 2, -1*marco + p.y - h / 2, capa1);
	glVertex3d(-1*marco + p.x - a / 2, marco + p.y + h / 2, capa1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(p.x + a / 2, p.y + h / 2, capa2);
	glVertex3d(p.x + a / 2, p.y - h / 2, capa2);
	glVertex3d(p.x - a / 2, p.y - h / 2, capa2);
	glVertex3d(p.x - a / 2, p.y + h / 2, capa2);
	glEnd();
	displayText(p.x - a/2 + marco, p.y + h/2 - 4*marco, capa3, 255, 255, 255, mensaje);
}

void HUD::dibuja(const char* mensaje) {
	float marco = 0.2;
	float h = getAlto();
	float a = getAncho();
	Vector2D p = getPos();
	glBegin(GL_POLYGON);
	glColor3f(255, 255, 255);
	glVertex3d(marco + p.x + a / 2, marco + p.y + h / 2, capa1);
	glVertex3d(marco + p.x + a / 2, -1 * marco + p.y - h / 2, capa1);
	glVertex3d(-1 * marco + p.x - a / 2, -1 * marco + p.y - h / 2, capa1);
	glVertex3d(-1 * marco + p.x - a / 2, marco + p.y + h / 2, capa1);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(p.x + a / 2, p.y + h / 2, capa2);
	glVertex3d(p.x + a / 2, p.y - h / 2, capa2);
	glVertex3d(p.x - a / 2, p.y - h / 2, capa2);
	glVertex3d(p.x - a / 2, p.y + h / 2, capa2);
	glEnd();
	displayText(p.x - a / 2 + marco, p.y + h / 2 - 4 * marco, capa3, 255, 255, 255, mensaje);
}


void HUD::mueve() {

}

void HUD::DibujaTienda(float camara_x, float camara_y)
{
	string mensaje = "";
	char char_arr[MAX_LENMENSAJE];
	char* char_arr2;
	char_arr[0] = '\0';
	setAlto(4);
	setAncho(18);
	setPos(camara_x, camara_y-4);
	string line;
	ifstream myfile("textos/TextoComerciante1.txt");
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
	dibuja(char_arr);
}

void HUD::DibujaTienda2(float camara_x, float camara_y)
{
	string mensaje = "";
	char char_arr[MAX_LENMENSAJE];
	char* char_arr2;
	char_arr[0] = '\0';
	setAlto(4);
	setAncho(6);
	setPos(camara_x+5, camara_y +3);
	string line;
	ifstream myfile("textos/TextoComerciante2.txt");
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
	dibuja(char_arr);
}

void HUD::DibujaTienda3(float camara_x, float camara_y)
{
	string mensaje = "";
	char char_arr[MAX_LENMENSAJE];
	char* char_arr2;
	char_arr[0] = '\0';
	setAlto(4);
	setAncho(18);
	setPos(camara_x, camara_y - 4);
	string line;
	ifstream myfile("textos/TextoComerciante3.txt");
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
	dibuja(char_arr);
}

void HUD::DibujaTienda4(float camara_x, float camara_y)
{
	string mensaje = "";
	char char_arr[MAX_LENMENSAJE];
	char* char_arr2;
	char_arr[0] = '\0';
	setAlto(7);
	setAncho(5);
	setPos(camara_x + 5, camara_y + 3);
	string line;
	ifstream myfile("textos/TextoComerciante4.txt");
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
	dibuja(char_arr);
}

void HUD::DibujaTiendaMaster(Protagonista *p, float camara_x, float camara_y)
{
	Vector2D prota = p->GetPos();
	if ((prota.x >= 105) && (prota.x <= 109) && (prota.y >= 80) && (prota.y <= 84))
	{
		DibujaTienda(camara_x, camara_y);
		DibujaTienda2(camara_x, camara_y);
	}
	if ((prota.x >= 107) && (prota.x <= 111) && (prota.y >= 96) && (prota.y <= 100))
	{
		DibujaTienda3(camara_x, camara_y);
		DibujaTienda4(camara_x, camara_y);
	}
}

void HUD::dibujaHUD(Protagonista *prota) {
	Vector2D prota_pos = prota->GetPos();
	setAlto(0.1);
	setAncho(3);
	setPos(prota_pos.x, prota_pos.y + 1.5f);
	float marco = 0.06f;
	float h = alto;
	float a = ancho;
	float hp = prota->getVida() / 100;
	//cout << hp << endl;
	Vector2D p = pos;
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3d(marco + p.x + a / 2, marco + p.y + h / 2, capa1);
	glVertex3d(marco + p.x + a / 2, -1 * marco + p.y - h / 2, capa1);
	glVertex3d(-1 * marco + p.x - a / 2, -1 * marco + p.y - h / 2, capa1);
	glVertex3d(-1 * marco + p.x - a / 2, marco + p.y + h / 2, capa1);
	glEnd();
	glBegin(GL_POLYGON);
	if (hp >= 0.66f)glColor3f(0, 255, 0);
	if ((hp < 0.66f) && (hp >= 0.33f))glColor3f(255, 255, 0);
	if (hp < 0.33f)glColor3f(255, 0, 0);
	if (hp > 0) {
		glVertex3d((p.x + a / 2) - a * (1 - hp), p.y + h / 2, capa2);
		glVertex3d((p.x + a / 2) - a * (1 - hp), p.y - h / 2, capa2);
		glVertex3d(p.x - a / 2, p.y - h / 2, capa2);
		glVertex3d(p.x - a / 2, p.y + h / 2, capa2);
	}
	//cout << getVida() << endl;
	glEnd();
}

std::string convert(float num) {
	std::ostringstream conv;
	conv << num;
	return conv.str();
}

std::string HUD::stringStats(Protagonista *p) {
	using namespace std;
	string hp = convert(p->getVida());
	string def = convert(p->getDef());
	string att = convert(p->getAttack());
	string v = convert(p->getVel());
	string as = convert(p->getAttackspeed());
	string money = convert(p->getDinero());
	string pocs = convert(p->getPociones());

	string a = "       ";
	string aux = "/100";

	//string str_stats = vida + hp + aux + '\n' + defensa + def + '\n' + ataque + att + '\n' + velocidad + v + '\n' + cooldown + cdown + '\n' + vel_ataque + as + '\n' + dinero + money + '\n';
	string str_stats = a + hp + aux + a + def + a + att + a + v + a + as + a + money + a + pocs;
	return str_stats;
}
void HUD::dibujaStats(Protagonista *p, float camara_x, float camara_y) {
	Vector2D prota_pos = p->GetPos();
	setAlto(1);
	setAncho(8);
	setPos(prota_pos.x, prota_pos.y);
	setPos(camara_x, camara_y);
	std::string stats = stringStats(p);
	const char* c = stats.c_str();
	dibuja(c);
	//std::cout << stats << std::endl;
}
