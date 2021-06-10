#include "Protagonista.h"
#include "ETSIDI.h"
#include <iostream>
#include <sstream>
#include "HUD.h"

Protagonista::Protagonista()
{
	setDir('d');
	spriteR.setCenter(1, 0);
	spriteR.setSize(1, 1);
	spriteL.setCenter(1, 0);
	spriteL.setSize(1, 1);
	spriteUp.setCenter(1, 0);
	spriteUp.setSize(1, 1);
	spriteDown.setCenter(1, 0);
	spriteDown.setSize(1, 1);

	posicion.x = 7;posicion.y = 122;velocidad.x = 0;velocidad.y = 0, velabs=1;
	setVida(100);
	//std::cout << "Vida: " << vida.getVida() << std::endl;
	hud.setAlto(0.1);
	hud.setAncho(3);
	hud.setPos(posicion.x, posicion.y + 1.5f);

	hud_stats.setAlto(1);
	hud_stats.setAncho(8);
	hud_stats.setPos(posicion.x, posicion.y);
}

void Protagonista::Dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.01);
	glColor3f(1.0f, 0.0f, 0.0f);
//gestion de direccion y animacion
	if (velocidad.x > 0.01)spriteR.draw();
	if (velocidad.x < -0.01)spriteL.draw();
	if ((velocidad.y > 0.01)&& (velocidad.x < 0.01) && (velocidad.x > -0.01))spriteUp.draw();
	if ((velocidad.y < -0.01)&&(velocidad.x < 0.01) && (velocidad.x > -0.01))spriteDown.draw();

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

	dibujaHUD();

	//dibujaStats();
}

void Protagonista::dibujaHUD() {
	float capa1 = 0.03f;
	float capa2 = 0.04f;
	float capa3 = 0.05f;
	float marco = 0.06f;
	float h = hud.getAlto();
	float a = hud.getAncho();
	float hp = getVida()/100;
	//cout << hp << endl;
	Vector2D p = hud.getPos();
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


void Protagonista::Mueve(float t)
{
	hud.setPos(posicion.x, posicion.y + 1.5f);
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


std::string convert(float num) {
	std::ostringstream conv;
	conv << num;
	return conv.str();
}

std::string Protagonista::stringStats() {
	using namespace std;
	string hp = convert(getVida());
	string def = convert(getDef());
	string att = convert(getAttack());
	string v = convert(getVel());
	string as = convert(getAttackspeed());
	string money = convert(getDinero());
	string pocs = convert(getPociones());

	string a = "       ";
	string aux = "/100";

	//string str_stats = vida + hp + aux + '\n' + defensa + def + '\n' + ataque + att + '\n' + velocidad + v + '\n' + cooldown + cdown + '\n' + vel_ataque + as + '\n' + dinero + money + '\n';
	string str_stats = a + hp + aux + a + def + a + att + a + v + a + as + a + money + a + pocs;
	return str_stats;
}
void Protagonista::dibujaStats(float camara_x, float camara_y) {
	hud_stats.setPos(camara_x, camara_y);
	std::string stats = stringStats();
	const char* c = stats.c_str();
	hud_stats.dibuja(c);
	//std::cout << stats << std::endl;
}